/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** my.h
*/

#ifndef _MY_H_
    #define _MY_H_

    #define RED "\x1B[1;31m"
    #define GREEN "\x1B[1;32m"
    #define RESET "\x1B[0m"
    #define PROMPT "[" GREEN "shell_1" RESET "] $> "
    #define PROMPT_ERR "[" RED "shell_1" RESET "] $> "

    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <dirent.h>
    #include <string.h>

    typedef struct info {
        char **copy_env;
        char **env_path;
        int semicolon;
        char **my_env;
        char **args;
        char *oldpwd;
        char *value;
        char *home;
        char *name;
        char *pwd;
        int overwrite;
    } info_t;

typedef void (*function_ptr_t)(info_t *);
extern function_ptr_t functions[];

/* LIB */
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int rows_string(char *str);
char **malloc_array(char *str);
int switch_check(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *str, char separator);
int my_atoi(char *str);
int my_str_isalpha(char *str);
char *my_realloc(char *ptr, size_t size);
void *my_memcpy(void *dest, const void *src, size_t n);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strdup(const char *s);

/* cd.c */
void check_for_cd(info_t *info);

/* errors_handling.c */
void command_exist(int child_ret, char **args);
void error_handling(int ac);
void handle_segfault(int child_ret, info_t *info);

/* exec_binary.c */
int check_binary(info_t *info);

/* generic_function.c */
int my_array_len(char **array);
void save_args(char **args, info_t *info);
void print_env(char **env);
char **copy_env(char **env);
int my_strcmp_start(const char *str1, const char *str2);

/* manage_struct.c */
void fill_struct(info_t *info, char **env);
void free_struct(info_t *info);

/* parther.c */
char *parse_path(char *s1, char *s2);
char *remove_newline(char *s);
char *parse_file_path(char *s);
char *delete_extra_space(char *str);
void parse_env_path(char **env, info_t *info);

/* set_env.c */
void set_env(info_t *info);
void var_one_name(info_t *info, int size_env, int name_len);
void var_name_value(info_t *info, int size_env, int name_len);
int check_alphanumeric_check(info_t *info);

/* set_args.c */
void set_one_args(info_t *info, int size_env);
void set_two_args(info_t *info, int size_env);

/* unset_env.c */
void unset_env(info_t *info);

/* pwd_old_new.c */
void set_pwd(info_t *info);

/* my_getenv.c */
char *my_getenv(const char *name, char **env);

/* parth_getline.c */
char *line_formatting(char *line);
char *get_env_var(char **env, char *var);
char *check_for_zero(char *input);

/* check_semicolons.c */
void check_for_semicolons(char *line, info_t *info);

#endif
