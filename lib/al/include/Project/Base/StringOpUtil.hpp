#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.hpp>

namespace al {
const char* getBaseName(const char*);
const char* createStringIfInStack(const char*);
char* createConcatString(const char*, const char*);
void createFileNameBySuffix(sead::BufferedSafeString*, const char*, const char*);
void outputValueWithComma(char*, u32, u64, bool, bool);
void extractString(char*, const char*, u32, u32);
const char* searchSubString(const char*, const char*);
const char* searchSubString(const char*, const char*, s32);

void removeExtensionString(char*, u32, const char*);
void removeStringFromEnd(char*, u32, const char*, const char*);
void translateCharacters(char*, const char*, const char*);
bool tryReplaceString(sead::BufferedSafeString*, const char*, const char*);
bool tryReplaceString(sead::BufferedSafeString*, const char*, const char*, const char*);

bool isEqualString(const char16*, const char16*);
bool isEqualSubString(const char*, const char*);
bool isEqualSubString(const sead::SafeString&, const sead::SafeString&);
bool isStartWithString(const char*, const char*);
bool isEndWithString(const char*, const char*);

s32 compareStringIgnoreCase(const char*, const char*);

void copyString(char*, const char*, u32);
void copyStringW(char16*, const char16*, u32);
}  // namespace al
