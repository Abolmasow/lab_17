int lengthOfString(char *str) {
    int length = 0;

    while (*str) {
        length++;
        str++;
    }

    return length;
}