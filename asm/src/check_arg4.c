/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"

int check_lfork(char **str, asm_t *all)
{
    if (str[2] != NULL)
        return -1;
    if (str[1] == NULL)
        return-1;
    if (str[1] != NULL) {
        if (is_t_dir_int(str[1], all) == -1 && is_t_dir_lab(str[1], all) == -1)
            return -1;
    }
    return 0;
}

int check_aff(char **str, asm_t *all)
{
    if (str[2] != NULL)
        return -1;
    if (str[1] == NULL)
        return-1;
    if (str[1] != NULL) {
        if (is_registre(str[1], all) == -1)
            return -1;
    }
    return 0;
}
