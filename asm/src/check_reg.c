/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"

int is_registre(char *str, asm_t *all)
{
    if (str[0] != 'r')
        return -1;
    if (str[1] == '\0' || str[1] == '0')
        return -1;
    if (str[2] == '\0' && str[1] != '\0') {
        if (str[1] >= '1' && str[1] <= '9') {
            all->champ_s += 1;
            return 0;
        }
        else
            return -1;
    }
    if (str[2] != '\0' && str[3] != '\0')
        return -1;
    if (str[2] != '\0' && str[3] == '\0') {
            if (str[1] != '1' || str[2] < '1' || str[2] > '6')
                return -1;
    }
    all->champ_s += 1;
    return 0;
}
