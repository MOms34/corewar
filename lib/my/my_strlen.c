/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count])
        count++;
    return count;
}
