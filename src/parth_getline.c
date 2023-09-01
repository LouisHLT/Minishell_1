/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** parth_getline.c
*/

#include "../include/my.h"

char *check_for_zero(char *input)
{
    input = remove_newline(input);
    return input;
}

char *line_formatting(char *input)
{
    int j = 0;
    int input_len = my_strlen(input);
    char *new_input = malloc(sizeof(char) * (input_len + 1));
    for (int i = 0; i < input_len; i++) {
        if (input[i] == '\t')
            input[i] = ' ';
    }
    for (int i = 0; i < input_len; i++) {
        if (input[i] == ' ') continue;
        while (input[i] != ' ' && input[i] != '\0') {
            new_input[j] = input[i];
            j++; i++;
        }
        if (input[i] == '\0')
            break;
        new_input[j] = ' ';
        j++;
    }
    new_input[j] = '\0';
    return new_input;
}

char *get_env_var(char **env, char *var)
{
    int len = my_strlen(var);
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], var, len) == 0)
            return env[i];
    }
    return NULL;
}
