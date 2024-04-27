#ifndef LAB_17_COUNTERPALINDROMEWORD_H
#define LAB_17_COUNTERPALINDROMEWORD_H

#include "../string_.h"
#include <assert.h>

int getSeparateWord(char* begin_search, wordDescriptor* word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    if (ispunct(*(word->end - 1)))
        word->end--;

    return true;
}

int counterPalindromeWords(char* s) {
    int amount_palindrome = 0;
    char* begin_search = s;
    wordDescriptor word;

    while (getSeparateWord(begin_search, &word)) {
        if (isPalindromeWord(&word))
            amount_palindrome++;

        if (ispunct(*(word.end)))
            word.end++;

        begin_search = word.end;
    }

    return amount_palindrome;
}

void test_8_non_palindrome() {
    char s[] = "apple, butter, bread";
    assert(counterPalindromeWords(s) == 0);
}


void test_8_only_letters() {
    char s[] = "a b c d";
    assert(counterPalindromeWords(s) == 4);
}


void test_8_only_palindrome() {
    char s[] = "arera, non, boob";
    assert(counterPalindromeWords(s) == 3);
}


void test_8_different_string() {
    char s[] = "boob, bread, non, arera, apple";
    assert(counterPalindromeWords(s) == 3);
}


void test_8_counter_palindrome_word() {
    test_8_non_palindrome();
    test_8_only_letters();
    test_8_only_palindrome();
    test_8_different_string();
}

#endif //LAB_17_COUNTERPALINDROMEWORD_H
