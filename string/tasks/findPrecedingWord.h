#ifndef LAB_17_FINDPRECEDINGWORD_H
#define LAB_17_FINDPRECEDINGWORD_H
#include "../string_.h"

wordDescriptor findPrecedingWord(char* s1, char* s2) {
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

    bool stop = false;
    wordDescriptor w;
    wordDescriptor preceding_w = {.begin = NULL, .end = NULL};

    for (size_t i = 1; i < _bag.size; i++) {
        w = _bag.words[i];
        for (size_t j = 0; j < _bag2.size; j++)
            if (isWordEqual(w, _bag2.words[j])) {
                stop = true;
                break;
            }

        if (stop) {
            preceding_w = _bag.words[i - 1];
            break;
        }

    }

    freeBag(&_bag);
    freeBag(&_bag2);

    return preceding_w;
}

void test_16_empty() {
    char s1[] = "";
    char s2[] = "";

    char dest[20] = "";
    wordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}

void test_16_first_empty() {
    char s1[] = "";
    char s2[] = "I like";

    char dest[20] = "";
    wordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}

void test_16_second_empty() {
    char s1[] = "I like";
    char s2[] = "";

    char dest[20] = "";
    wordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}

void test_16_not_in_string() {
    char s1[] = "I like tea";
    char s2[] = "she drinks";

    char dest[20] = "";
    wordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("", dest);
}

void test_16_first_in_string() {
    char s1[] = "He likes tea";
    char s2[] = "she likes coffee";

    char dest[20] = "";
    wordDescriptor word = findPrecedingWord(s1, s2);

    wordDescriptorToString(word, dest);

    ASSERT_STRING("He", dest);
}

void test_16_find_preceding_word() {
    test_16_empty();
    test_16_first_empty();
    test_16_second_empty();
    test_16_not_in_string();
    test_16_first_in_string();
}

#endif //LAB_17_FINDPRECEDINGWORD_H
