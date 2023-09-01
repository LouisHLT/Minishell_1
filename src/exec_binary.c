/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** exec_binary.c
*/

#include "../include/my.h"

static char *get_executable(char **args)
{
    int binary_len = my_strlen(args[0]) - 2;
    char *executable = malloc(sizeof(char) * (binary_len + 1));
    if (executable == NULL) {
        perror("malloc");
        exit(1);
    }
    my_strncpy(executable, args[0] + 2, binary_len);
    executable[binary_len] = '\0';
    return executable;
}

static int search_binary(char *executable, char **path)
{
    char *new_exec = NULL;
    for (int i = 0; path[i] != NULL; i++) {
        int path_len = my_strlen(*path);
        int exec_len = path_len + my_strlen(executable) + 2;
        new_exec = malloc(exec_len);
        if (new_exec == NULL) {
            perror("malloc");
            free(executable); exit(1);
        }
        my_strcpy(new_exec, *path);
        my_strcpy(new_exec + path_len, "/");
        my_strcpy(new_exec + path_len + 1, executable);
        if (access(new_exec, X_OK) == 0) {
            free(executable); return 0;
        }
        free(new_exec);
    }
    free(executable);
    return 1;
}

int check_binary(info_t *info)
{
    int bin_ok = 1;
    struct stat file;
    if (stat(info->args[0], &file) == -1) {
        return 0;
    }
    if (!S_ISREG(file.st_mode)) {
        return 0;
    }
    if (file.st_mode & S_IXUSR) {
        char *executable = get_executable(info->args);
        bin_ok = search_binary(executable, info->my_env);
    } else {
        bin_ok = 1;
    }
    return bin_ok;
}
