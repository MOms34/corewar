/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get_nbr
*/

#include "my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int odd_or_even = 1;
    int result = 0;

    while ('-' == str[i] || '+' == str[i]) {
        if (str[i] == '-') {
            odd_or_even = odd_or_even * (-1);
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * odd_or_even);
}
