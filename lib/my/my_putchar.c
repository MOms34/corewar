/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    if (write(1, &c, sizeof(char)) == -1)
        my_put_error("ERROR : Write did not work!\n");
}
