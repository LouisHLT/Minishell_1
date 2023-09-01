/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** mini version on printf
*/

#include "../../include/my.h"

int switch_check(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case 'd':
    case 'i': my_put_nbr(va_arg(list, int)); i++; break;
    case 'c': my_putchar(va_arg(list, int)); i++; break;
    case 's': my_putstr(va_arg(list, char *)); i++; break;
    case '%': my_putchar('%'); i++; break;
    }
    return i;
}

int my_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i = switch_check(format, i, list);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return 0;
}
