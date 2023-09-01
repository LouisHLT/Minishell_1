/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** main.c
*/

#include "include/my.h"

static void exec_function(info_t *info)
{
    char *temp = NULL; int child_ret;
    pid_t child_pid;
    int bin_exe = check_binary(info);
    if (bin_exe == 1) {
        if (access(info->args[0], X_OK) == 0)
            temp = info->args[0];
        else {
            my_printf("%s: Permission denied.\n", info->args[0]);
            my_printf(PROMPT_ERR); return;
        }
    } else
        temp = parse_path("/bin/", info->args[0]);
    child_pid = fork();
    if (child_pid == -1) { return;
    } else if (child_pid == 0) {
        execve(temp, info->args, info->my_env); exit(EXIT_FAILURE);
    } else {
        waitpid(child_pid, &child_ret, 0);
        handle_segfault(child_ret, info);
    }
}

static void check_custom_function(info_t *info)
{
    const char *commands[] = {"", "exit", "cd", "setenv",
    "unsetenv", "env", NULL};
    int i = 0;

    while (commands[i]) {
        if (my_strcmp(info->args[0], commands[i]) == 0) {
            functions[i](info);
            return;
        }
        i++;
    }
    exec_function(info);
}

void execute_semicolons(char *line, info_t *info)
{
    char **args = my_str_to_word_array(line, ';');
    for (int i = 0; args[i] != NULL; i++) {
        args[i] = line_formatting(args[i]);
        char **temp = my_str_to_word_array(args[i], ' ');
        save_args(temp, info);
        check_custom_function(info);
    }
}

static void engine(info_t *info)
{
    ssize_t read;
    size_t len = 0;
    char *line = NULL;
    while (1) {
        read = getline(&line, &len, stdin);
        if (read == -1) {
            my_printf("\nexit\n"); exit(0);
        }
        line = line_formatting(line);
        line = check_for_zero(line);
        if (info->semicolon == 1) {
            execute_semicolons(line, info);continue;
        }
        char **args = my_str_to_word_array(line, ' ');
        save_args(args, info);
        if (info->args[0] == NULL)
            continue;
        check_custom_function(info); free(line);
        line = NULL;
    }
}

int main(int ac, char **av, char **env)
{
    error_handling(ac);
    (void)av;
    info_t *info = malloc(sizeof(info_t));
    fill_struct(info, env);
    my_printf(PROMPT);
    parse_env_path(env, info);
    engine(info);
    free_struct(info);
    return 0;
}
