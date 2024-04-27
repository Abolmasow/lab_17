#ifndef LAB_17_SWAPWORDS_H
#define LAB_17_SWAPWORDS_H

#include "../string_.h"

void appendWord(char* result, wordDescriptor* word) {
    char* ptr = result;
    while (*ptr != '\0') {
        ptr++;
    }

    char* start = word->begin;
    while (*start != *word->end) {
        *ptr = *start;
        ptr++;
        start++;
    }

    *ptr = ' ';
    ptr++;
    *ptr = '\0';
}


void mergeWords(char* s1, char* s2, char* result) {
    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            appendWord(result, &word1);
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            appendWord(result, &word2);
            beginSearch2 = word2.end;
        }
    }
}

void test_9_empty() {
    char result[100] = "";

    char s1[] = "";
    char s2[] = "";

    mergeWords(s1, s2, result);

    ASSERT_STRING("", result);
}


void test_9_one_string_empty() {
    char result[100] = "";

    char s1[] = "";
    char s2[] = "test";

    mergeWords(s1, s2, result);

    ASSERT_STRING("test ", result);
}

void test_9_different_string() {
    char result[100] = "";

    char s1[] = "I";
    char s2[] = "LIKE";

    mergeWords(s1, s2, result);

    ASSERT_STRING("I LIKE ", result);
}


void test_9_different_amount_word_1() {
    char result[100] = "";

    char s1[] = "test";
    char s2[] = "word letter ";

    mergeWords(s1, s2, result);

    ASSERT_STRING("test word letter ", result);
}


void test_9_different_amount_word_2() {
    char result[100] = "";

    char s1[] = "word letter";
    char s2[] = "test";

    mergeWords(s1, s2, result);

    ASSERT_STRING("word test letter ", result);
}

void test_9_swap_words() {
    test_9_empty();
    test_9_one_string_empty();
    test_9_different_string();
    test_9_different_amount_word_1();
    test_9_different_amount_word_2();
}

#endif //LAB_17_SWAPWORDS_H
