#ifndef LAB_17_REMOVENONLETTERS_H
#define LAB_17_REMOVENONLETTERS_H
#include <ctype.h>
#include "../string_.h"

void removeNonLetters(char* s) {
    char* end = getEndOfString(s);
    char* destination = copyIf(s, end, s, isgraph);

    *destination = '\0';
}

void test_1_empty() {
    char s[] = " ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_2_non_space() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_3_space() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_4_space_in_border() {
    char s[] = "   Hi    12 3    ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_1_remove_non_letters() {
    test_1_empty();
    test_2_non_space();
    test_3_space();
    test_4_space_in_border();
}
#endif //LAB_17_REMOVENONLETTERS_H
