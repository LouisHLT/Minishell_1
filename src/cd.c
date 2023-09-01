/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** cd.c
*/

#include "../include/my.h"

void set_pwd(info_t *info)
{
    char *cwd = getcwd(NULL, 0);
    info->args = (char *[]) {"set_env", "PWD", cwd, NULL};
    set_env(info);
}

static void set_oldpwd(info_t *info)
{
    char *cwd = getcwd(NULL, 0);
    info->args = (char *[]) {"set_env", "OLDPWD", cwd, NULL};
    set_env(info);
}

static void go_home(info_t *info)
{
    char *home_path = get_env_var(info->my_env, "HOME");
    if (home_path == NULL) {
        my_printf(": No such file or directory.\n");
        set_oldpwd(info);
    }
    info->home = get_env_var(info->my_env, "HOME");
    if (chdir(info->home + 5) == 0) {
        functions[0](info);
    } else {
        perror("cd");
    }
}

static void cd_old_dir(info_t *info, char *cwd, char *temp_oldpwd)
{
    if (temp_oldpwd == NULL) {
        my_printf(": No such file or directory.\n");
        my_printf(PROMPT_ERR);
    } else {
        char *goal = get_env_var(info->my_env, "OLDPWD");
        if (chdir(goal + 7) == 0) {
            char *temp = get_env_var(info->my_env, "OLDPWD");
            info->args = (char *[]) {"set_env", "PWD", temp, NULL};
            set_env(info);
            info->args = (char *[]) {"set_env", "OLDPWD", cwd, NULL};
            set_env(info);
            my_printf("%s\n", getcwd(NULL, 0));
        }
        functions[0](info);
        return;
    }
}

void check_for_cd(info_t *info)
{
    char *cwd = getcwd(NULL, 0);
    char *temp_oldpwd = get_env_var(info->my_env, "OLDPWD");
    if (info->args[1] == NULL || my_strcmp(info->args[1], "~") == 0) {
        go_home(info); return;
    }
    if (info->args[1] != NULL && chdir(info->args[1]) == 0 &&
    my_strcmp(info->args[1], "-") != 0) {
        info->args = (char *[]) {"set_env", "OLDPWD", cwd, NULL};
        set_env(info);
        set_pwd(info);
        functions[0](info);
    } else if (my_strcmp(info->args[1], "-") != 0) {
        my_printf("%s: No such file or directory.\n", info->args[1]);
        my_printf(PROMPT_ERR);
    }
    if (info->args[1] != NULL && my_strcmp(info->args[1], "-") == 0) {
        cd_old_dir(info, cwd, temp_oldpwd);
    }
}
