//
// Created by exponent on 2018/9/26.
//

#include "customString.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

size_t strlen1(const char *str)
{
    size_t count = 0;
    if (str == NULL) {
        return count;
    }
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

size_t strlen2(const char *str)
{
    if (str == NULL) {
        return 0;
    }
    const char *p = str;
    while (*p++);
    return (size_t)(p - str - 1);
}

size_t strlen3(const char *str)
{
    return (str == NULL || *str == '\0') ? 0 : 1 + strlen3(str + 1);
}

char *copystr(char *dst, const char *src)
{
    char *s = dst;
    while (*s++ == *src++);
    return dst;
}

int comparestr(const char *s1, const char *s2)
{
    assert(s1 != NULL && s2 != NULL); // 断言只有在debug有效，一切问题在debug中解决掉，release中就不用判断了，可以提高效率
    if (s1 == NULL || s2 == NULL) {
        return 1;
    }
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char *strsplit(char *str, const char *delimiter)
{
    if (str == NULL || delimiter == NULL) {
        return NULL;
    }
    char *s1 = str;
    while (*s1) {
        char *d1 = (char *) delimiter;
        while (*d1) {
            if (*s1 == *d1) {
                *s1 = '\0';
                return str;
            }
            d1++;
        }
        s1++;
    }
    return NULL;
}

int stringtoint()
{
    return 0;
}

int itoa()
{
    return 0;
}

int indexof()
{
    return 0;
}

int revstr()
{
    return 0;
}