#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* hourTryParse(int h)
{
    char* s = malloc(10 * sizeof(char));
    switch (h) {
        case 1: return s = "one";
        case 2: return s = "two";
        case 3: return s = "three";
        case 4: return s = "four";
        case 5: return s = "five";
        case 6: return s = "six";
        case 7: return s = "seven";
        case 8: return s = "eight";
        case 9: return s = "nice";
        case 10: return s = "ten";
        case 11: return s = "eleven";
        case 12: return s = "twelve";
    }
    return s;
}
char* minuteTryParse(int m)
{
    char* s = malloc(20 * sizeof(char));
    int h = 0;
    if(m <= 30)
    {
        h = m;
    }
    else {
        h = 60 - m;
    }
    switch (h) {
        case 1: return s = "one";
        case 2: return s = "two";
        case 3: return s = "three";
        case 4: return s = "four";
        case 5: return s = "five";
        case 6: return s = "six";
        case 7: return s = "seven";
        case 8: return s = "eight";
        case 9: return s = "nice";
        case 10: return s = "ten";
        case 11: return s = "eleven";
        case 12: return s = "twelve";
        case 13: return s = "thirteen";
        case 14: return s = "fourteen";
        case 15: return s = "quarter";
        case 16: return s = "sixteen";
        case 17: return s = "seventeen";
        case 18: return s = "eighteen";
        case 19: return s = "nineteen";
        case 20: return s = "twenty";
        case 21: return s = "twenty one";
        case 22: return s = "twenty two";
        case 23: return s = "twenty three";
        case 24: return s = "twenty four";
        case 25: return s = "twenty five";
        case 26: return s = "twenty six";
        case 27: return s = "twenty seven";
        case 28: return s = "twenty eight";
        case 29: return s = "twenty nine";
        case 30: return s = "half";
    }
    return s;
}
char* timeInWords(int h, int m) {
    char* s = malloc(100 * sizeof(char));
    if(m == 0)
    {
        strcpy(s, hourTryParse(h));
        strcat(s, " o' clock");               
    }
    else if (m < 30 && m != 15 && m != 1) {
        strcpy(s, minuteTryParse(m));
        strcat(s, " minutes past ");
        strcat(s, hourTryParse(h));              
    }
    else if (m > 30 && m != 45) {
        strcpy(s, minuteTryParse(m));
        strcat(s, " minutes to ");
        strcat(s, hourTryParse(h + 1));
    }
    else if (m == 15) {
        strcpy(s, minuteTryParse(m));
        strcat(s, " past ");
        strcat(s, hourTryParse(h));
    }
    else if (m == 45) {
        strcpy(s, minuteTryParse(m));
        strcat(s, " to ");
        strcat(s, hourTryParse(h + 1));
    }
    else if (m == 30) {
        strcpy(s, minuteTryParse(m));
        strcat(s, " past ");
        strcat(s, hourTryParse(h));
    }
    else {
        strcpy(s, minuteTryParse(m));
        strcat(s, " minute past ");
        strcat(s, hourTryParse(h));
    }
    return s; 
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int h = parse_int(ltrim(rtrim(readline())));

    int m = parse_int(ltrim(rtrim(readline())));

    char* result = timeInWords(h, m);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
