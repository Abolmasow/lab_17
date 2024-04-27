#ifndef LAB_17_REVERSSTR_H
#define LAB_17_REVERSSTR_H
#include "../string_.h"
#include <ctype.h>

void digitToStart(wordDescriptor word) {
    char* end_string_buffer = copy(word.begin, word.end, _string_buffer);

    char* res_position = copyIfReverse(end_string_buffer - 1, _string_buffer - 1, word.begin, isdigit);

    copyIf(_string_buffer, end_string_buffer, res_position, isalpha);
}

void invertedDigitToStartLettersToEnd(char* s) {
    char* begin_search = s;
    wordDescriptor word;

    while (getWord(begin_search, &word)) {
        digitToStart(word);
        begin_search = word.end;
    }
}

void reverseWord(wordDescriptor word) {
    char* start = word.begin;
    char* end = word.end - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void reverseWordInString(char* s) {
    char* begin_search = s;
    wordDescriptor word;

    while (getWord(begin_search, &word)) {
        reverseWord(word);
        begin_search = word.end;
    }
}

void test_3_empty() {
    char s[] = "";
    reverseWordInString(s);
    ASSERT_STRING("", s);
}


void test_3_one_letters() {
    char s[] = "a";
    reverseWordInString(s);
    ASSERT_STRING("a", s);
}


void test_3_one_word() {
    char s[] = "abcd";
    reverseWordInString(s);
    ASSERT_STRING("dcba", s);
}


void test_3_two_word() {
    char s[] = "abcde aaa";
    reverseWordInString(s);
    ASSERT_STRING("edcba aaa", s);
}


void test_3_reverse_word() {
    test_3_empty();
    test_3_one_letters();
    test_3_one_word();
    test_3_two_word();
}

#endif //LAB_17_REVERSSTR_H
