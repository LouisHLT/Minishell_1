/*
** EPITECH PROJECT, 2022
** louis
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *str)
{
    int i = 0;
    int str_len = my_strlen(dest);
    for (i = 0; str[i] != '\0'; i++) {
        dest[str_len + i] = str[i];
    }
    dest[str_len + i] = '\0';
    return dest;
}
