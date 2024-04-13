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
char* copyIfReverse(const char *r_begin_source, const char *r_end_source, char
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