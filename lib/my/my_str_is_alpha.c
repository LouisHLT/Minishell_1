/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** my_str_is_alpha.c
*/

#include "../../include/my.h"

int	my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            i = i + 1;
        else
            return 0;
    }
    return 1;
}
