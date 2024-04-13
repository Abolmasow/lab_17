#include "string_.h"

int lengthOfString(char *str) {
    int length = 0;

    while (*str) {
        length++;
        str++;
    }

    return length;
}

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }
    return end - begin;
}
