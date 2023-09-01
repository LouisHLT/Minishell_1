/*
** EPITECH PROJECT, 2022
** louis
** File description:
** my_strlen.c
*/


int my_strlen(char const *str)
{
    int temp = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        temp = temp + 1;
    }
    return temp;
}
