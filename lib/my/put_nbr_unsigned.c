/*
** EPITECH PROJECT, 2021
** my_printf_checker
** File description:
** my_printf_checker
*/

#include "my.h"

void my_put_unsigned(unsigned int nb)
{
    int c;

    if (nb > 9) {
        c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else {
        my_putchar(nb + 48);
    }
}
