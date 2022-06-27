/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** str_cmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while ((*s1 == *s2) && (*s1 != '\0')) {
        s1 += 1;
        s2 += 1;
    }
    return (*s1 - *s2);
}
