/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** free_structure.c
*/

#include "../include/my.h"

void fill_struct(info_t *info, char **env)
{
    info->my_env = copy_env(env);
    info->copy_env = copy_env(env);
}

void free_struct(info_t *info)
{
    for (int i = 0; info->my_env[i]; i++)
        free(info->my_env[i]);
    free(info->my_env);
    for (int i = 0; info->copy_env[i]; i++)
        free(info->copy_env[i]);
    for (int i = 0; info->env_path[i]; i++)
        free(info->env_path[i]);
    for (int i = 0; info->args[i]; i++)
        free(info->args[i]);
    free(info->value);
    free(info->name);
    free(info->copy_env);
    free(info);
}
