/*
** EPITECH PROJECT, 2022
** Shell_1
** File description:
** my_realloc.c
*/

#include "../include/my.h"

char *my_realloc(char *ptr, size_t size)
{
    char *new_ptr = malloc(size);
    if (!new_ptr) {
        return NULL;
    }
    if (ptr) {
        for (size_t i = 0; i < size; i++) {
            new_ptr[i] = ptr[i];
        }
        free(ptr);
    }
    return new_ptr;
}
