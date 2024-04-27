#ifndef LAB_17_LEXICOGRAPHICALSTR_H
#define LAB_17_LEXICOGRAPHICALSTR_H
#include "../string_.h"
#include <assert.h>

int areWordsEqual(wordDescriptor w1, wordDescriptor w2) {
    while (*w1.begin && (*w1.begin == *w2.begin)) {
        w1.begin++;
        w2.begin++;
    }

    return *(const unsigned char*) w1.begin - *(const unsigned char*) w2.begin;
}

bool isLexicographicalOrder(char* s) {
    char* begin_search = s;
    wordDescriptor word1, word2;

    if (!getWord(begin_search, &word1))
        return true;

    begin_search = word1.end;

    while (getWord(begin_search, &word2)) {
        if (areWordsEqual(word1, word2) <= 0)
            word1 = word2;
        else
            return false;

        begin_search = word2.end;
    }

    return true;
}

void test_6_empty() {
    char s[] = "";
    assert(isLexicographicalOrder(s));
}

void test_6_one_letters() {
    char s[] = "a";
    assert(isLexicographicalOrder(s));
}

void test_6_letters_ordered() {
    char s[] = "a b c";
    assert(isLexicographicalOrder(s));
}

void test_6_letters_unordered() {
    char s[] = "a e c";
    assert(!isLexicographicalOrder(s));
}

void test_6_word_ordered() {
    char s[] = "abs abs def";
    assert(isLexicographicalOrder(s));
}

void test_6_word_unordered() {
    char s[] = "def abs abs";
    assert(!isLexicographicalOrder(s));
}

void test_6_lexicographical_str() {
    test_6_empty();
    test_6_one_letters();
    test_6_letters_ordered();
    test_6_letters_unordered();
    test_6_word_ordered();
    test_6_word_unordered();
}

#endif //LAB_17_LEXICOGRAPHICALSTR_H
