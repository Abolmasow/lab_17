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

// 2
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


void test () {
    test_length_of_string();
    test_strlen_();
}

int main() {
    test;
    return 0;
}