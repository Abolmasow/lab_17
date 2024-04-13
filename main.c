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

// 5
void test_strcmp_is_equal() {
    char s1[] = "123";
    char s2[] = "123";
    assert(strcmp_(s1, s2) == 0);
}

void test_strcmp_is_not_equal_1() {
    char s1[] = "123";
    char s2[] = "456";
    assert(strcmp_(s1, s2) == -3);
}

void test_strcmp_is_not_equal_2() {
    char s1[] = "125";
    char s2[] = "123";
    assert(strcmp_(s1, s2) == 2);
}

void test_strcmp_() {
    test_strcmp_is_equal();
    test_strcmp_is_not_equal_1();
    test_strcmp_is_not_equal_2();
}

// 6 (a)
void test_copy_1() {
    char s[] = "test";
    char s_copy[10];
    copy(s, s + strlen_(s), s_copy);
    assert(strcmp_(s_copy, "test") == 0);
}
void test_copy_2() {
    char s[] = "";
    char s_copy[10];
    copy(s, s + strlen_(s), s_copy);
    assert(strcmp_(s_copy, "") == 0);
}
void test_copy() {
    test_copy_1();
    test_copy_2();
}
// 6 (b)
void test_copy_if() {
    char s[] = "1abcd";
    char s_copy[15];
    copyIf(s, s + strlen_(s), s_copy, isalpha);
    assert(strcmp_(s_copy, "abcd") == 0);
}

// 6 (c)
void test_copy_if_reverse() {
    char s[] = "f1s2a3";
    char s_copy[15];
    copyIfReverse(s + strlen_(s) - 1, s - 1, s_copy, isdigit);
    assert(strcmp_(s_copy, "123") == 0);
}

void test () {
    test_length_of_string();
    test_strlen_();
    test_find();
    test_find_non_space();
    test_find_space();
    test_find_non_space_reverse();
    test_find_space_reverse();
    test_strcmp_;
    test_copy();
    test_copy_if();
    test_copy_if_reverse();

}

int main() {
    test;
    return 0;
}