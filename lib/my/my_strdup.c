/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** my_strdup.c
*/

#include "../../include/my.h"

char *my_strdup(const char *str)
{
    int length = my_strlen(str);
    char *dup = malloc(sizeof(char) * (length + 1));
    my_strcpy(dup, str);
    return dup;
}
