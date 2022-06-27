/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** my_putnbr
*/

#include "my.h"

void my_put_nbr(int nb)
{
    int c;

    if (nb == -2147483648) {
        my_putstr("-2");
        my_put_nbr(147483648);
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9) {
        c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else {
        my_putchar(nb + 48);
    }
}
