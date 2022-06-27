/*
** EPITECH PROJECT, 2021
** my_basics_print
** File description:
** my_basic_print
*/

#include "my.h"

int print_int(va_list arg)
{
    int nb = va_arg(arg, int);
    int count = 0;

    my_put_nbr(nb);
    if (nb < 0) {
        count = count + 1;
        nb = nb * -1;
    }
    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    count = count + 1;
    return count;
}

int print_char(va_list arg)
{
    my_putchar(va_arg(arg, int));
    return 1;
}

int print_string(va_list arg)
{
    char *str = va_arg(arg, char *);

    my_putstr(str);
    return my_strlen(str);
}

int print_unsigned_int(va_list arg)
{
    unsigned int nb = va_arg(arg, int);
    int count = 0;

    my_put_unsigned(nb);
    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    count = count + 1;
    return count;
}
