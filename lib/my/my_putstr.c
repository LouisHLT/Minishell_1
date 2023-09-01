/*
** EPITECH PROJECT, 2022
** louis
** File description:
** my_putstr.c
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    for (i; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
