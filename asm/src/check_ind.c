/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"

int is_indir_num(char *str, asm_t *all)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && i > 0)
            return (-1);
        if (str[i] == '-' && i == 0)
            i++;
        if (is_digit(str[i], all) != 1 ) {
            return -1;
        }
    }
    all->champ_s += 2;
    return 0;
}

int is_indir_label(char *str, asm_t *all)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[0] != ':')
            return -1;
        if (i > 0 && is_label(str[i], all) != 1)
            return -1;
    }
    all->champ_s += 2;
    return 0;
}
