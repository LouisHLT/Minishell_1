/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** my_getenv.c
*/

#include "../include/my.h"

char *my_getenv(const char *name, char **env)
{
    int i;
    int len = strlen(name);
    char *result = NULL;

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            result = env[i] + len + 1;
            break;
        }
    }
    return result;
}
