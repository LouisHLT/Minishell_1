/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** errors_handling.c
*/

#include "../include/my.h"

void error_handling(int ac)
{
    if (ac != 1) {
        my_printf("Usage: ./mysh\n");
        exit(84);
    }
}

void command_exist(int child_ret, char **args)
{
    if (WIFEXITED(child_ret)) {
        int ret = WEXITSTATUS(child_ret);
        if (ret != 0) {
            int sig = WTERMSIG(child_ret);
            my_printf("%s: Command not found.\n", args[0]);
            strsignal(sig);
            my_printf(PROMPT_ERR);
        } else {
            my_printf(PROMPT);
        }
    } else if (WIFSIGNALED(child_ret)) {
        int sig = WTERMSIG(child_ret);
        (void)sig;
    }
}

void handle_segfault(int child_ret, info_t *info)
{
    if (WIFSIGNALED(child_ret)) {
        int sig = WTERMSIG(child_ret);
        if (sig == SIGSEGV) {
            my_printf("%s\n", strsignal(sig));
            my_printf(PROMPT_ERR);
        }
    }
    command_exist(child_ret, info->args);
}
