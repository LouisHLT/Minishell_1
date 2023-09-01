/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** my_aoit.c
*/

#include "../../include/my.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str[0] == '-') {
        neg = -1;
        i++;
    }
    while (str[i] != '\0') {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb * neg);
}
