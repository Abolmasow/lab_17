#ifndef LAB_17_REMOVEPALINDROMEWORD_H
#define LAB_17_REMOVEPALINDROMEWORD_H

#include "../string_.h"

void removePalindromeWord(char* s) {
    char* read_begin = _string_buffer;
    char* read_end = copy(s, s + strlen_(s), _string_buffer);
    char* rec_ptr = s;

    wordDescriptor word;
    while (getWord(read_begin, &word)) {
        if (!isPalindromeWord(&word)) {
            rec_ptr = copy(word.begin, word.end, rec_ptr);

            if (word.end !=  read_end)
                *rec_ptr++ = ' ';
        }
        read_begin = word.end + 1;
    }

    *rec_ptr = '\0';

    freeString(_string_buffer);
}

void test_17_empty() {
    char s[] = "";
    removePalindromeWord(s);
    ASSERT_STRING("", s);
}

void test_17_no_palindrome() {
    char s[] = "no palindrome";
    removePalindromeWord(s);
    ASSERT_STRING("no palindrome", s);
}

void test_17_only_letters() {
    char s[] = "a b c d";
    removePalindromeWord(s);
    ASSERT_STRING("", s);
}

void test_17_different_string() {
    char s[] = "adda are word a b she word";
    removePalindromeWord(s);
    ASSERT_STRING("are word she word", s);
}

void test_17_remove_palindrome_word() {
    test_17_empty();
    test_17_no_palindrome();
    test_17_only_letters();
    test_17_different_string();
}

#endif //LAB_17_REMOVEPALINDROMEWORD_H
