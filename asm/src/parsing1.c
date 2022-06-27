/*
** EPITECH PROJECT, 2022
** asm
** File description:
** corewar
*/

#include "asm.h"
#include "my.h"

int limitp(char a, char *limit)
{
    int z = 0;

    while (z != my_strlen(limit)) {
        if (limit[z] == a)
            return (-1);
        z++;
    }
    return (0);
}
