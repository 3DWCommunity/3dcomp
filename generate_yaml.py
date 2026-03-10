import csv
import yaml
from collections import defaultdict

TSV_PATH = "data/unit_funcs.tsv"
CSV_PATH = "data/bf_functions.csv"
OUTPUT_PATH = "data/units.yml"

BASE_ADDRESS = 0x7100000000

_markers = {
    "O": "Matching",
    "m": "Equivalent",
    "M": "NonMatching",
    "W": "Wip",
    "U": "NotDecompiled",
    "L": "NotDecompiled",
}


class HexInt(int):
    pass


def hexint_representer(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:int", f"0x{data:06X}")


def str_representer(dumper, data):
    if data.startswith("."):
        return dumper.represent_scalar("tag:yaml.org,2002:str", data, style="'")
    return dumper.represent_scalar("tag:yaml.org,2002:str", data)


yaml.SafeDumper.add_representer(HexInt, hexint_representer)
yaml.SafeDumper.add_representer(str, str_representer)


def load_symbol_to_object():
    symbol_map = {}

    current_folder = ""
    current_object = ""

    with open(TSV_PATH, encoding="utf-8") as f:
        reader = csv.DictReader(f, delimiter="\t")

        for row in reader:
            folder = row["Folder"].strip()
            obj = row["Object"].strip()
            mangled = row["Mangled Name"].strip()

            if folder:
                current_folder = folder

            if obj:
                current_object = obj

            if not current_object:
                continue

            path = f"{current_folder}/{current_object}" if current_folder else current_object
            symbol_map[mangled] = path

    return symbol_map


def generate_yaml():
    symbol_to_object = load_symbol_to_object()

    units = defaultdict(lambda: {".text": []})

    with open(CSV_PATH, encoding="utf-8") as f:
        reader = csv.reader(f)

        for row in reader:
            address, marker, size_hex, symbol = row

            if symbol not in symbol_to_object:
                continue

            obj_path = symbol_to_object[symbol]

            offset = int(address, 16) - BASE_ADDRESS
            size = int(size_hex)

            entry = {
                "offset": HexInt(offset),
                "size": size,
                "label": symbol,
                "status": _markers.get(marker, "Unknown"),
            }

            units[obj_path][".text"].append(entry)

    for obj in units:
        units[obj][".text"].sort(key=lambda x: x["offset"])

    units = dict(units)

    with open(OUTPUT_PATH, "w", encoding="utf-8") as f:
        yaml.safe_dump(units, f, sort_keys=False)


if __name__ == "__main__":
    generate_yaml()