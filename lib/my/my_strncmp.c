/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** my_strncmp.c
*/

#include "../../include/my.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n && s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
