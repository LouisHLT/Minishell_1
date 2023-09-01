/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** env.c
*/
#include "../include/my.h"

int check_alphanumeric_check(info_t *info)
{
    int i = 0; int valid = 1;
    if ((info->args[1][0] <= '0' && info->args[1][0] >= '9') ||
        (info->args[1][0] <= 'A' && info->args[1][0] >= 'Z') ||
        (info->args[1][0] <= 'a' && info->args[1][0] >= 'z') ||
        (info->args[1][0] == '_')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        valid = 0;
    }
    for (; info->args[1][i] != '\0'; i++) {
        if (info->args[1][i] >= '0' && info->args[1][i] <= '9') continue;
        if (info->args[1][i] >= 'A' && info->args[1][i] <= 'Z') continue;
        if (info->args[1][i] >= 'a' && info->args[1][i] <= 'z') continue;
        if (info->args[1][i] == '_') continue;
        my_printf("setenv: Variable name must contain alphanumeric");
        my_printf(" characters.\n");
        valid = 0; break;
    }
    return valid;
}

void var_name_value(info_t *info, int size_env, int name_len)
{
    char **copy_env = malloc(sizeof(char *) * (size_env + 2));
    int i = 0;
    for (; info->my_env[i] != NULL; i++) {
        copy_env[i] = malloc(sizeof(char) * (my_strlen(info->my_env[i]) + 1));
        my_strcpy(copy_env[i], info->my_env[i]);
    }
    copy_env[i] = NULL;
    for (i = 0; info->my_env[i] != NULL; i++)
        free(info->my_env[i]);
    info->my_env = malloc(sizeof(char *) *(my_array_len(info->my_env) + 2));
    for (i = 0; copy_env[i] != NULL; i++) {
        info->my_env[i] = malloc(sizeof(char) * (my_strlen(copy_env[i]) + 1));
        my_strcpy(info->my_env[i], copy_env[i]);
    }
    char *temp = malloc(sizeof(char) * (name_len));
    my_strcpy(temp, info->args[1]);
    my_strcat(temp, "=");
    my_strcat(temp, info->args[2]);
    info->my_env[i] = my_strdup(temp);
    info->my_env[i + 1] = NULL; free(temp);
}

void var_one_name(info_t *info, int size_env, int name_len)
{
    char **copy_env = malloc(sizeof(char *) * (size_env + 2));
    int i = 0;
    for (; info->my_env[i] != NULL; i++) {
        copy_env[i] = malloc(sizeof(char) * (my_strlen(info->my_env[i]) + 1));
        my_strcpy(copy_env[i], info->my_env[i]);
    }
    copy_env[i] = NULL;
    for (i = 0; info->my_env[i] != NULL; i++)
        free(info->my_env[i]);
    info->my_env = malloc(sizeof(char *) * (my_array_len(info->my_env) + 2));
    for (i = 0; copy_env[i] != NULL; i++) {
        info->my_env[i] = malloc(sizeof(char) * (my_strlen(copy_env[i]) + 1));
        my_strcpy(info->my_env[i], copy_env[i]);
    }
    char *temp = malloc(sizeof(char) * (name_len + 2));
    my_strcpy(temp, info->args[1]);
    my_strcat(temp, "=");
    info->my_env[i] = my_strdup(temp);
    info->my_env[i + 1] = NULL; free(temp); functions[0](info);
}

void set_env(info_t *info)
{
    info->overwrite = 1;
    int nbr_args = my_array_len(info->args);
    int size_env = my_array_len(info->my_env);
    if (nbr_args > 3) {
        my_printf("setenv: Too many arguments\n"); my_printf(PROMPT_ERR);
        return;
    }
    if (info->args[1] == NULL) {
        print_env(info->my_env); 
        functions[0](info); return;
    }
    if (nbr_args == 2)
        set_one_args(info, size_env);
    if (nbr_args == 3) {
        set_two_args(info, size_env);
    }
}
