#include <stdio.h>
#include <assert.h>
#include "string/string_.h"

//2
void test_length_of_string_is_not_empty() {
    char s[] = "Hello";

    assert(lengthOfString(s) == 5);
}

void test_length_of_string_is_empty() {
    char s[] = "";

    assert(lengthOfString(s) == 0);
}

void test_length_of_string_is_exceeds_the_size() {
    char s[10] = "Hello";

    assert(lengthOfString(s) == 5);
}

void test_length_of_string() {
    test_length_of_string_is_not_empty();
    test_length_of_string_is_empty();
    test_length_of_string_is_exceeds_the_size();
}

//3
void test_strlen_is_not_empty() {
    char s[] = "\tHello\t";

    assert(strlen_(s) == 7);
}

void test_strlen_is_empty() {
    char s[] = "";

    assert(strlen_(s) == 0);
}

void test_strlen_() {
    test_strlen_is_not_empty();
    test_strlen_is_empty();
}

// 4 (a)
void test_find_is_enabled() {
    char s[] = "Hello";
    char *begin = &s[0];
    char *end = &s[3];
    assert(find(begin, end,'e') == &s[1]);
}

void test_find_is_not_enabled() {
    char s[] = "Hello";
    char *begin = &s[0];
    char *end = &s[3];
    assert(find(begin, end,'o') == &s[3]);
}

void test_find() {
    test_find_is_enabled();
    test_find_is_not_enabled();
}

// 4 (b)
void test_find_non_space_is_space() {
    char s[] = "\t 3 4 5";
    assert(findNonSpace(s) == &s[3]);
}

void test_find_non_space_is_no_space() {
    char s[] = "12345";
    assert(findNonSpace(s) == &s[0]);
}

void test_find_non_space_is_space_and_no_elements() {
    char s[] = " ";
    assert(findNonSpace(s) == &s[4]);
}

void test_find_non_space() {
    test_find_non_space_is_space();
    test_find_non_space_is_no_space();
    test_find_non_space_is_space_and_no_elements();
}

// 4 (c)
void test_find_space_is_space_and_no_elements() {
    char s[] = " ";
    assert(findSpace(s) == &s[0]);
}

void test_find_space_is_space() {
    char s[] = "1234 ";
    assert(findSpace(s) == &s[4]);
}

void test_find_space_is_no_space() {
    char s[] = "12345";
    assert(findSpace(s) == &s[5]);
}

void test_find_space() {
    test_find_space_is_space_and_no_elements();
    test_find_space_is_space();
    test_find_space_is_no_space();
}

// 4 (d)
void test_find_non_space_reverse_is_no_space() {
    char s[] = "123";
    assert(findNonSpaceReverse(&s[2],&s[0]) == &s[2]);
}

void test_find_non_space_reverse_is_last_element() {
    char s[] = " 3";
    assert(findNonSpaceReverse(&s[3],&s[0]) == &s[3]);
}

void test_find_non_space_reverse_is_no_element() {
    char s[] = " ";
    assert(findNonSpaceReverse(&s[3],&s[0]) == &s[0]);
}

void test_find_non_space_reverse_is_not_last() {
    char s[] = " 3 ";
    assert(findNonSpaceReverse(&s[3],&s[0]) == &s[2]);
}

void test_find_non_space_reverse() {
    test_find_non_space_reverse_is_no_space();
    test_find_non_space_reverse_is_last_element();
    test_find_non_space_reverse_is_no_element();
    test_find_non_space_reverse_is_not_last();
}

// 4 (e)
void test_find_space_reverse_is_no_space() {
    char s[] = "123";
    assert(findSpaceReverse(&s[2],&s[0]) == &s[0]);
}

void test_find_space_reverse_is_last_space() {
    char s[] = "12 ";
    assert(findSpaceReverse(&s[3],&s[0]) == &s[3]);
}

void test_find_space_reverse_is_not_last_space() {
    char s[] = "12 23";
    assert(findSpaceReverse(&s[5],&s[0]) == &s[3]);
}

void test_find_space_reverse() {
    test_find_space_reverse_is_no_space();
    test_find_space_reverse_is_last_space();
    test_find_space_reverse_is_not_last_space();
}


void test () {
    test_length_of_string();
    test_strlen_();
    test_find();
    test_find_non_space();
    test_find_space();
    test_find_non_space_reverse();
    test_find_space_reverse();
}

int main() {
    test;
    return 0;
}