#ifndef LAB_17_CHANGEWORDORDER_H
#define LAB_17_CHANGEWORDORDER_H
#include "../string_.h"

void changeWordOrder(char *s) {
    if (strlen_(s) == 0)
        return;

    char* rec_ptr = s;

    char* r_buffer_begin = copy(s, s + strlen_(s), _string_buffer) - 1;
    char* r_buffer_end = _string_buffer;

    wordDescriptor word;
    while (getWordReverse(r_buffer_begin, r_buffer_end, &word)) {
        rec_ptr = copy(word.begin, word.end + 1, rec_ptr);
        if (word.begin != r_buffer_end) {
            *rec_ptr++ = ' ';
        }

        r_buffer_begin = word.begin - 2;
    }

    *rec_ptr = '\0';

    freeString(_string_buffer);
}

void test_10_empty() {
    char s[] = "";
    changeWordOrder(s);
    ASSERT_STRING("", s);
}


void test_10_one_word() {
    char s[] = "world";
    changeWordOrder(s);
    ASSERT_STRING("world", s);
}


void test_10_only_letters() {
    char s[] = "a b c d";
    changeWordOrder(s);
    ASSERT_STRING("d c b a", s);
}


void test_10_different_word() {
    char s[] = "world apple test";
    changeWordOrder(s);
    ASSERT_STRING("test apple world", s);
}


void test_10_change_word_order() {
    test_10_empty();
    test_10_one_word();
    test_10_only_letters();
    test_10_different_word();
}

#endif //LAB_17_CHANGEWORDORDER_H
