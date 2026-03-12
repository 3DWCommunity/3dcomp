import sys
import csv
from pathlib import Path

TSV_FILE = "data/unit_funcs.tsv"

def load_symbol_map():
    symbol_map = {}

    current_folder = ""
    current_object = ""

    with open(TSV_FILE, newline='', encoding="utf-8") as f:
        reader = csv.DictReader(f, delimiter="\t")

        for row in reader:
            if row["Folder"].strip():
                current_folder = row["Folder"].strip()

            if row["Object"].strip():
                current_object = row["Object"].strip()

            mangled = row["Mangled Name"].strip()
            if not mangled:
                continue

            if current_folder and current_object:
                cpp_name = Path(current_object).stem + ".cpp"
                symbol_map[mangled] = f"{current_folder}/{cpp_name}"

    return symbol_map


def main():
    if len(sys.argv) != 2:
        print("Usage: python lookup.py <mangled_symbol>")
        sys.exit(1)

    symbol_name = sys.argv[1]
    symbol_map = load_symbol_map()

    if symbol_name in symbol_map:
        print(symbol_map[symbol_name])
    else:
        print("Symbol not found.")


if __name__ == "__main__":
    main()