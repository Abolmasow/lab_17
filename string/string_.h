#ifndef LAB_17_STRING__H
#define LAB_17_STRING__H

// возвращает длину строки
int lengthOfString(char *str);

// возвращает количество символов в строке size_t strlen_(const char* begin);
// возвращает указатель на первый элемент, расположенным между адресами begin и end не включая end.
char* find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, если символ не найден, возвращается адрес первого ноль-символа.
char* findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ или на первый ноль-символ.
char* findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных, еслисимвол не
//найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа, tсли символ не найден,
//возвращается адрес rend.
char* findSpaceReverse(char *rbegin, const char *rend);

// Функция возвращает отрицательное значение, если lhs располагается до rhs
// значение 0, если lhs и rhs равны,
// иначе – положительное значение
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource
// Возвращает указатель на следующий свободный фрагмент памяти в destination.
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

// записывает по адресу beginDestination элементы начиная с beginSource заканчивая
//endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
char* copyIf(const char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char* copyIfReverse(const char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif //LAB_17_STRING__H
