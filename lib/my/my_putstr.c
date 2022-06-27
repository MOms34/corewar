/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** put_str
*/

#include "my.h"

void my_putstr(char const *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a = a + 1)
        my_putchar(str[a]);
}
