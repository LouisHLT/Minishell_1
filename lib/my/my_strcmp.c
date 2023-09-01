/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** my_strcmp.c
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len = my_strlen(s1);
    int size;

    if (my_strlen(s1) < my_strlen(s2))
        len = my_strlen(s2);

    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            size = s1[i] - s2[i];
            return (1);
        }
    }

    return (0);
}
