#ifndef LAB_17_GETWORDBEFOREFIRSTWORDA_H
#define LAB_17_GETWORDBEFOREFIRSTWORDA_H

#include <assert.h>
#include "../string_.h"

typedef enum wordBeforeFirstWordWithAReturnCode {
    EMPTY_STRING,
    NOT_FOUND_A_WORD_WITH_A,
    FIRST_WORD_WITH_A,
    WORD_FOUND
} wordBeforeFirstWordWithAReturnCode;

bool isLettersInWord(wordDescriptor word, char letters) {
    char* start = word.begin;

    while (start != word.end) {
        if (*start == letters)
            return true;

        start++;
    }

    return false;
}

wordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordA(char* s, wordDescriptor* word) {
    char* begin_search = s;

    wordDescriptor word1;
    if (!getWord(begin_search, &word1)) {
        return EMPTY_STRING;
    }
    begin_search = word1.end + 1;



    if (isLettersInWord(word1, 'a') || isLettersInWord(word1, 'A')) {
        return FIRST_WORD_WITH_A;
    }

    wordDescriptor word2;
    while (getWord(begin_search, &word2)) {
        if (isLettersInWord(word2, 'a') || isLettersInWord(word2, 'A')) {
            *word = word1;
            return WORD_FOUND;
        }

        word1 = word2;

        begin_search = word2.end + 1;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void test_11_get_word_before_first_word_with_a() {
    wordDescriptor word;

    char s1[] = "";
    assert(getWordBeforeFirstWordA(s1, &word) == EMPTY_STRING);

    char s2[] = "abc";
    assert(getWordBeforeFirstWordA(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "bc a";
    assert(getWordBeforeFirstWordA(s3, &word) == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("bc", got);

    char s4[] = "b q we nw";
    assert(getWordBeforeFirstWordA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

#endif //LAB_17_GETWORDBEFOREFIRSTWORDA_H
