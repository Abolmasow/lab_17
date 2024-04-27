#include <stdio.h>
#include "string_.h"
#include <stdbool.h>

char _string_buffer[MAX_STRING_SIZE + 1];

int lengthOfString(char *str) {
    int length = 0;

    while (*str) {
        length++;
        str++;
    }

    return length;
}

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }
    return begin;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }
    return begin;
}
char* findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }
    return begin;
}
char* findNonSpaceReverse(char *r_begin, const char *r_end) {
    while (r_begin != r_end && isspace(*r_begin)) {
        r_begin--;
    }
    return r_begin;
}

char* findSpaceReverse(char *r_begin, const char *r_end) {
    while (r_begin != r_end && !isspace(*r_begin)) {
        r_begin--;
    }
    return r_begin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *(const unsigned char*) lhs - *(const unsigned char*) rhs;
}

char* copy(const char* begin_source, const char* end_source, char* begin_destination) {
    while (begin_source != end_source) {
        *begin_destination = *begin_source;
        ++begin_source;
        ++begin_destination;
    }
    return begin_destination;
}
char* copyIf(const char* begin_source, const char* end_source, char* begin_destination,
              int (*f)(int)) {
    while (begin_source != end_source) {
        if (f(*begin_source)) {
            *begin_destination = *begin_source;
            begin_destination++;
        }
        begin_source++;
    }
    return begin_destination;
}
char* copyIfReverse(char *r_begin_source, char *r_end_source, char
*begin_destination, int (*f)(int)) {
    char* start = r_begin_source;
    while (start != r_end_source) {
        if (f(*start)) {
            *begin_destination = *start;
            begin_destination++;
        }
        start--;
    }
    return begin_destination;
}

char* getEndOfString(char* s) {
    char* start = s;
    while (*start != '\0')
        start++;

    return start;
}

void assertString(const char* expected, char* got, char const* file_name, char const* func_name, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", file_name);
        fprintf(stderr, "%s - failed on line %d\n", func_name, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", func_name);
}

bool getWord(char* begin_search, wordDescriptor* word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
}

bool getWordWithoutSpace(char* begin_search, wordDescriptor* word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin) - 1;

    return true;
}

bool getWordReverse(char* r_begin, char* r_end, wordDescriptor* word) {
    if (word->begin == r_end)
        return false;

    word->end = findNonSpaceReverse(r_begin, r_end);

    word->begin = findSpaceReverse(r_begin, r_end);
    word->begin = word->begin == r_end ? word->begin : word->begin + 1;

    return true;
}

void freeString(char* string) {
    char* ptr = string;
    while (*ptr) {
        *ptr = '\0';
        ptr++;
    }
}