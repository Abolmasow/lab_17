#ifndef LAB_17_FINDWITHTHESAMELETTERSWORDS_H
#define LAB_17_FINDWITHTHESAMELETTERSWORDS_H

#include <stdlib.h>
#include <assert.h>
#include "../string_.h"

int compareLetters(const void* s1, const void* s2) {
    return *(char *) s1 - *(char *) s2;
}

void sortWordLetters(wordDescriptor* word) {
    qsort(word->begin, word->end - word->begin, sizeof(char), compareLetters);
}

bool areIdenticalWordsInString(char* s) {
    char* begin_buff = _string_buffer;

    copy(s, s + strlen_(s), _string_buffer);

    while (getWordWithoutSpace(begin_buff, &_bag.words[_bag.size])) {
        begin_buff = _bag.words[_bag.size].end + 2;
        _bag.size++;
    }

    freeString(_string_buffer);

    if (_bag.size <= 1)
        return false;

    for (size_t i = 0; i < _bag.size; i++)
        sortWordLetters(&_bag.words[i]);

    for (size_t i = 0; i < _bag.size; i++)
        for (size_t j = i + 1; j < _bag.size; j++)
            if (isWordEqual(_bag.words[i], _bag.words[j])) {
                freeBag(&_bag);
                return true;
            }

    freeBag(&_bag);
    return false;
}

void test_14_empty() {
    char s[] = "";
    assert(!areIdenticalWordsInString(s));
}


void test_14_one_word() {
    char s[] = "word";
    assert(!areIdenticalWordsInString(s));
}


void test_14_with_the_same_letters_words_not_in_string() {
    char s[] = "duplicate not in string";
    assert(!areIdenticalWordsInString(s));
}


void test_14_with_the_same_letters_words_in_string() {
    char s[] = "string in string";
    assert(areIdenticalWordsInString(s));
}


void test_14_find_with_the_same_letters_words() {
    test_14_empty();
    test_14_one_word();
    test_14_with_the_same_letters_words_not_in_string();
    test_14_with_the_same_letters_words_in_string();
}

#endif //LAB_17_FINDWITHTHESAMELETTERSWORDS_H
