/*
** EPITECH PROJECT, 2022
** Minishell_1
** File description:
** array_of_function_pointer.c
*/

#include "../include/my.h"

void my_print_wrapper(void)
{
    my_printf(PROMPT);
}

void print_env_wrapper(info_t *info)
{
    print_env(info->my_env);
    functions[0](info);
}

void exit_wrapper(void)
{
    exit(0);
}

function_ptr_t functions[] = {
    (function_ptr_t)&my_print_wrapper,
    (function_ptr_t)&exit_wrapper,
    (function_ptr_t)&check_for_cd,
    (function_ptr_t)&set_env,
    (function_ptr_t)&unset_env,
    (function_ptr_t)&print_env_wrapper,
};
