#ifndef LAB_17_FINDLASTCOMMONWORD_H
#define LAB_17_FINDLASTCOMMONWORD_H
#include "../string_.h"

wordDescriptor findLastCommonWord(char* s1, char* s2) {
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;

    while (getWordWithoutSpace(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (getWordWithoutSpace(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }

    wordDescriptor word = {.begin = NULL, .end = NULL};
    for (int i = (int) _bag.size - 1; i >= 0; i--)
        for (int j = 0; j < _bag2.size; j++)
            if (isWordEqual(_bag.words[i], _bag2.words[j])) {
                word = _bag.words[i];

                freeBag(&_bag);
                freeBag(&_bag2);

                return word;
            }

    return word;
}

void test_12_word_at_end() {
    char s1[] = "I like to drink of tea";
    char s2[] = "drink coffee";

    char dest[MAX_WORD_SIZE] = "";
    wordDescriptor word = findLastCommonWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("drink", dest);
}


void test_12_no_common_word() {
    char s1[] = "I like to drink of tea";
    char s2[] = "She does not eat fruit";

    char dest[MAX_WORD_SIZE] = "";
    wordDescriptor word = findLastCommonWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}


void test_12_word_at_start() {
    char s1[] = "drink tea";
    char s2[] = "drink coffee";

    char dest[MAX_WORD_SIZE] = "";
    wordDescriptor word = findLastCommonWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("drink", dest);
}


void test_12_single_word_strings() {
    char s1[] = "drink";
    char s2[] = "drink";

    char dest[MAX_WORD_SIZE] = "";
    wordDescriptor word = findLastCommonWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("drink", dest);
}


void test_12_find_last_common_word() {
    test_12_word_at_end();
    test_12_word_at_start();
    test_12_no_common_word();
    test_12_single_word_strings();
}

#endif //LAB_17_FINDLASTCOMMONWORD_H
