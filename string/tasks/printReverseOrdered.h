#ifndef LAB_17_PRINTREVERSEORDERED_H
#define LAB_17_PRINTREVERSEORDERED_H

#include "../string_.h"

void getBagOfWords(bagOfWords* bag, char* s) {

    char* begin_search = s;
    bag->size = 0;

    while (getWord(begin_search, &bag->words[bag->size])) {
        begin_search = bag->words[bag->size].end;

        bag->size++;
    }
}


void printWord1(wordDescriptor word) {
    while (word.begin != word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }
    printf(" ");
}


void printReverseOrdered(char* s) {
    getBagOfWords(&_bag, s);

    if (_bag.size >= 1)
        for (int i = (int) _bag.size - 1; i >= 0; i--)
            printWord1(_bag.words[i]);

    printf("\n");

    freeBag(&_bag);
}

void test_7_empty() {
    char s[] = "";
    printReverseOrdered(s);
}


void test_7_one_word() {
    char s[] = "like";
    printReverseOrdered(s);
}


void test_7_only_letters() {
    char s[] = "l i k";
    printReverseOrdered(s);
}


void test_7_more_word() {
    char s[] = "I like to drink tea";
    printReverseOrdered(s);
}


void test_7_print_reverse_ordered() {
    printf("test 7: \n");
    test_7_empty();
    test_7_one_word();
    test_7_only_letters();
    test_7_more_word();
    printf("\n");
}

#endif //LAB_17_PRINTREVERSEORDERED_H
