#ifndef LAB_17_LETTERSBELONGSTRING_H
#define LAB_17_LETTERSBELONGSTRING_H

#include <assert.h>
#include "../string_.h"

#define LETTERS_SHIFT 97

bool lettersBelongString(char* string, wordDescriptor word) {
    bool include[26] = {0};

    char* start = string;
    char* end = getEndOfString(string);

    while (start != end) {
        if (isalpha(*start))
            include[*start - LETTERS_SHIFT] = true;

        start++;
    }

    while (word.begin != word.end) {
        if (!include[*word.begin - LETTERS_SHIFT])
            return false;

        word.begin++;
    }

    return true;
}

void test_19_empty() {
    char string[] = "";
    wordDescriptor word;
    getWord("", &word);

    assert(!lettersBelongString(string, word));
}

void test_19_empty_word() {
    char string[] = "word";
    wordDescriptor word;
    getWord("", &word);

    assert(!lettersBelongString(string, word));
}

void test_19_empty_string() {
    char string[] = "";
    wordDescriptor word;
    getWord("word", &word);

    assert(!lettersBelongString(string, word));
}

void test_19_letters_not_in_string() {
    char string[] = "abc";
    wordDescriptor word;
    getWord("word", &word);

    assert(!lettersBelongString(string, word));
}

void test_19_letters_in_string() {
    char string[] = "world";
    wordDescriptor word;
    getWord("word", &word);

    assert(lettersBelongString(string, word));
}

void test_19_letters_belong_string() {
    test_19_empty();
    test_19_empty_word();
    test_19_empty_string();
    test_19_letters_not_in_string();
    test_19_letters_in_string();
}

#endif //LAB_17_LETTERSBELONGSTRING_H
