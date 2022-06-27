/*
** EPITECH PROJECT, 2022
** my_put_error
** File description:
** my_put_erro
*/

#include "my.h"

void my_put_error(char *str)
{
    write(2, str, my_strlen(str));
    exit(ERROR);
}
