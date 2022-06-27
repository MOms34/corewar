/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** str_ncat
*/

#include "my.h"

char *my_strncat(char *dest , char const *src , int nb)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i += 1);
    for (; j < nb && src[j] != '\0'; j += 1, i += 1) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}
