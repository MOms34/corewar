/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"

static flag_t flag[] =
{
    {'d', print_int},
    {'i', print_int},
    {'c', print_char},
    {'s', print_string},
    {'u', print_unsigned_int},
    {'o', print_octal},
    {'x', print_hexa_min},
    {'X', print_hexa_maj},
    {'%', print_percent},
    {'b', print_bin},
};

var_t cut_printf(char const *fmt, var_t var, va_list ap)
{
    int array_size = 9;

    for (int a = 0; a <= array_size; a++) {
        if (fmt[var.i] == '%' && fmt[var.i + 1] == flag[a].c) {
            var.nb = var.nb + flag[a].fmt(ap);
            a = -1;
            var.i = var.i + 2;
        }
    }
    return (var);
}

int my_printf(char const *fmt, ...)
{
    var_t var;
    var.nb = 0;
    va_list(ap);
    va_start(ap, fmt);

    for (var.i = 0; var.i < my_strlen(fmt); var.i++) {
        var = cut_printf(fmt, var, ap);
        if (var.i < my_strlen(fmt)) {
            write(1, &fmt[var.i], 1);
            var.nb++;
        }
    }
    va_end(ap);
    return var.nb;
}
