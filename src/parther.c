/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** parther.c
*/

#include "../include/my.h"
#include <string.h>

char *parse_path(char *s1, char *s2)
{
    int i = 0, j = 0;
    int len = my_strlen(s1) + my_strlen(s2) + 1;
    char *str = malloc(sizeof(char) * len);
    if (str == NULL) {
        perror("malloc failed");
        return NULL;
    }
    while (s1[i] != '\0') {
        str[i] = s1[i];
        i++;
    }
    int s2_len = my_strlen(s2);
    if (s2[s2_len - 1] == '\n') {
        s2[s2_len - 1] = '\0';
    }
    for (j = 0; s2[j] != '\0'; j++, i++) {
        str[i] = s2[j];
    }
    str[i] = '\0';
    return str;
}

char *remove_newline(char *s)
{
    int len = my_strlen(s);
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
    return s;
}

char *parse_file_path(char *s)
{
    char *new_path = malloc(sizeof(char) * my_strlen(s) + 4);
    my_strcpy(new_path, "./");
    my_strcat(new_path, s);
    my_strcat(new_path, "/");
    new_path[my_strlen(new_path)] = '\0';
    return new_path;
}

char *delete_extra_space(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            i++;
        } else {
            new_str[j] = str[i];
            i++;
            j++;
        }
    }
    new_str[j] = '\0';
    return new_str;
}

void parse_env_path(char **env, info_t *info)
{
    char *temp = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            temp = my_strdup(env[i] + 5);
        }
    }
    info->env_path = my_str_to_word_array(temp, ':');
}
