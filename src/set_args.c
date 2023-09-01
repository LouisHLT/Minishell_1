 /*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** set_args.c
*/

#include "../include/my.h"

void set_one_args(info_t *info, int size_env)
{
    int found = 0; int index = -1;
    int name_len = my_strlen(info->args[1]);
    int valid_name = check_alphanumeric_check(info);
    for (int i = 0; i < size_env; i++) {
        char *var = info->my_env[i];
        if (my_strncmp(var, info->args[1], name_len) == 0 &&
            var[name_len] == '=') { found = 1; index = i; break;
        }
    }
    if (found) {
        free(info->my_env[index]);
        info->my_env[index] = malloc(sizeof(char) * (name_len + 2));
        my_strcpy(info->my_env[index], info->args[1]);
        my_strcat(info->my_env[index], "="); functions[0](info);
    } else {
        if (!valid_name) {
            my_printf(PROMPT_ERR); return;
        } else
            var_one_name(info, size_env, name_len);
    }
}

void write_args(int found, info_t *info, int size_env, int index)
{
    int name_len = my_strlen(info->args[1]);
    if (found) {
        char *temp = malloc(sizeof(char) *
        (name_len + my_strlen(info->args[2]) + 2));
        my_strcpy(temp, info->args[1]);
        my_strcat(temp, "=");
        my_strcat(temp, info->args[2]);
        free(info->my_env[index]);
        info->my_env[index] = my_strdup(temp); free(temp); functions[0](info);
    } else {
        int valid_name = check_alphanumeric_check(info);
        if (!valid_name) {
            my_printf(PROMPT_ERR); return;
        } else
            var_name_value(info, size_env, name_len +
            my_strlen(info->args[2]) + 2); functions[0](info);
    }
}

void set_two_args(info_t *info, int size_env)
{
    int found = 0; int index = -1;
    int name_len = my_strlen(info->args[1]);
    for (int i = 0; i < size_env; i++) {
        char *var = info->my_env[i];
        if (my_strncmp(var, info->args[1], name_len) == 0 &&
        var[name_len] == '=') {
            found = 1; index = i; break;
        }
    }
    write_args(found, info, size_env, index);
}
