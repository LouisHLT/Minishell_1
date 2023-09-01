/*
** EPITECH PROJECT, 2022
** shell_2
** File description:
** check_semicolons.c
*/

#include "../include/my.h"

void check_for_semicolons(char *line, info_t *info)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ';') {
            info->semicolon = 1;
    }
}
