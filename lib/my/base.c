/*
** EPITECH PROJECT, 2021
** manage_base
** File description:
** manage_base
*/

#include "my.h"

int putnbr_base(unsigned int n, char const *base, int count)
{
    unsigned int i = my_strlen(base);

    if (n >= i) {
        count++;
        count = putnbr_base((n / i), base, count);
        my_putchar(base[(n % i)]);
    } else {
        my_putchar(base[n]);
        count++;
    }
    return count;
}

int print_hexa_min(va_list arg)
{
    return putnbr_base(va_arg(arg, int), "0123456789abcdef", 0);
}

int print_hexa_maj(va_list arg)
{
    return putnbr_base(va_arg(arg, int), "0123456789ABCDEF", 0);
}

int print_octal(va_list arg)
{
    return putnbr_base(va_arg(arg, int), "01234567", 0);
}

int print_bin(va_list arg)
{
    return putnbr_base(va_arg(arg, int), "01", 0);
}
