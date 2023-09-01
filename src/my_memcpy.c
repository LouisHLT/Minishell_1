/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** my_memcpy.c
*/

#include "../include/my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
