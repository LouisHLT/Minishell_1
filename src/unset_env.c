/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** unsetenv.c
*/

#include "../include/my.h"

static void delete_line(info_t *info, int i,int size)
{
    int j = 0;
    char **new_env = malloc(sizeof(char *) * (size + 1));

    for (j = 0; j < i; j++)
        new_env[j] = my_strdup(info->my_env[j]);
    for (j = i; j < size - 1; j++)
        new_env[j] = my_strdup(info->my_env[j + 1]);
    new_env[j] = NULL;
    free(info->my_env);
    info->my_env = new_env;
}

static void extra_if(info_t *info, int i, char **temp)
{
    int size = my_array_len(info->my_env);
    if (info->my_env == NULL || size <= 0)
        return;
    for (int j = 0; j < size && info->my_env[j] != NULL; j++) {
        if (my_strncmp(info->my_env[j], temp[i], my_strlen(temp[i])) == 0 &&
        info->my_env[j][my_strlen(temp[i])] == '=') {
            free(info->my_env[j]);
            delete_line(info, j, size);
            size--;
        }
    }
}

void unset_env(info_t *info)
{
    if (my_array_len(info->args) < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        my_printf(PROMPT_ERR);
        return;
    }
    char **temp = malloc(sizeof(char *) * (my_array_len(info->args) + 1));
    for (int i = 0; info->args[i] != NULL; i++)
        temp[i] = my_strdup(info->args[i]);
    temp[my_array_len(info->args)] = NULL;
    for (int i = 0; temp[i] != NULL; i++) {
        extra_if(info, i, temp);
    }
    functions[0](info);
}
