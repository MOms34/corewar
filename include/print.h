/*
** EPITECH PROJECT, 2021
** print_h
** File description:
** print_h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct var {
    int i;
    int nb;
}var_t;

typedef struct flag_s {
    char c;
    int (*fmt)(va_list);
}flag_t;

void my_put_unsigned(unsigned int nb);
int putnbr_base(unsigned int n, char const *base, int count);
int print_unsigned_int(va_list arg);
int print_octal(va_list arg);
int print_hexa_maj(va_list arg);
int print_hexa_min(va_list arg);
int print_int(va_list arg);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_bin(va_list arg);
int my_printf(char const *fmt, ...);
var_t cut_printf(char const *fmt, var_t var, va_list ap);
