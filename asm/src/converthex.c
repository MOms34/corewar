/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"

int convert(int data)
{
    int num = data;
    int b0,b1,b2,b3;
    int res;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;

    res = b0 | b1 | b2 | b3;
    return res;
}
