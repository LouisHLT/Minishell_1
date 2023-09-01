/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** my_strncpy.c
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;
    for (i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
