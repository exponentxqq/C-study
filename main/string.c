//
// Created by exponent on 2018/9/25.
//

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <sys/errno.h>
#include "customString.h"

void printString()
{
    char *str1 = "hello world!您好，世界！";
    wchar_t *str2 = L"hello world!您好，世界！";

    char buf1[128] = {};
    wchar_t buf2[128] = {};

    printf("string1=%s\n", str1);
    printf("string2=%p\n", str2);

    printf("string1 length=%ld\n", strlen(str1));
    printf("string2 length=%ld\n", wcslen(str2));

    strncpy(buf1, str1, 127);
    printf("buffer1=%s\n", buf1);
    wcsncpy(buf2, str2, 127);
    printf("buffer2=%ls\n", buf2);
}

void split()
{
    char str[] = "192.168.111.121";
    const char *delimiter = ".";
    char *p = strtok(str, delimiter);
    while (NULL != p) {
        printf("%s\n", p);
        p = strtok(NULL, delimiter);
    }
}

extern int errno;

void split2()
{
    char str[] = "192.168,111 121";
    char *next = NULL;
    const char *delimiter = "., ";
    char *p = strtok_r(str, delimiter, &next);
    while (p != NULL) {
        printf("%s\n", p);
        p = strtok_r(NULL, delimiter, &next);
    }
}

int main()
{
    printString();
    split();
    split2();

    char *str = "hello world!";
    printf("strlen1=%zu\n", strlen1(str));
    printf("strlen1=%zu\n", strlen2(str));
    printf("strlen1=%zu\n", strlen3(str));

    errno_t err = errno;
    return 0;
}