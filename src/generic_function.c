/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** generic_function.c
*/

#include "../include/my.h"

int my_array_len(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}

void save_args(char **args, info_t *info)
{
    int i;
    int len = 0;
    for (i = 0; args[i]; i++)
        len++;
    info->args = malloc(sizeof(char *) * (len + 1));
    for (i = 0; args[i]; i++)
        info->args[i] = my_strdup(args[i]);
    info->args[i] = NULL;

    for (int i = 0; info->args[i]; i++) {
        info->args[i] = remove_newline(info->args[i]);
    }
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
}

char **copy_env(char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (my_array_len(env) + 1));

    for (i = 0; env[i]; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        my_strcpy(new_env[i], env[i]);
    }
    new_env[i] = NULL;
    return new_env;
}

int my_strcmp_start(const char *str1, const char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len1 < len2)
        return -1;

    return my_strncmp(str1, str2, len2);
}
