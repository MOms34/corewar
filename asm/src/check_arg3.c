/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"

int check_ldi(char **str, asm_t *all)
{
    if (str[2] == NULL || str[1] == NULL || str[3] == NULL || str[4] != NULL)
        return -1;
    if (is_t_dir_int(str[1], all) == -1 && is_t_dir_lab(str[1], all) == -1
    && is_indir_label(str[1], all) == -1 && is_indir_num(str[1], all) == -1
    && is_registre(str[1], all))
        return -1;
    if (is_t_dir_int(str[2], all) == -1 && is_t_dir_lab(str[2], all) == -1
    && is_registre(str[2], all) == -1)
        return -1;
    if (is_registre(str[3], all) != 0)
        return -1;
    return 0;
}

int check_sti(char **str, asm_t *all)
{
    if (str[2] == NULL || str[1] == NULL || str[3] == NULL || str[4] != NULL)
        return -1;
    if (is_registre(str[1], all) != 0)
        return -1;
    if (is_t_dir_int(str[2], all) == -1 && is_t_dir_lab(str[2], all) == -1
    && is_indir_label(str[2], all) == -1 && is_indir_num(str[2], all) == -1
    && is_registre(str[2], all))
        return -1;
    if (is_t_dir_int(str[3], all) == -1 && is_t_dir_lab(str[3], all) == -1
    && is_registre(str[3], all) == -1)
        return -1;
    return 0;
}

int check_fork(char **str, asm_t *all)
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

int check_lld(char **str, asm_t *all)
{
    if (str[2] == NULL || str[1] == NULL || str[3] != NULL)
        return -1;
    if (is_t_dir_int(str[1], all) == -1 && is_t_dir_lab(str[1], all) == -1
    && is_indir_label(str[1], all) == -1 && is_indir_num(str[1], all) == -1)
        return -1;
    if (is_registre(str[2], all) != 0)
        return -1;
    return 0;
}

int check_lldi(char **str, asm_t *all)
{
    if (str[2] == NULL || str[1] == NULL || str[3] == NULL || str[4] != NULL)
        return -1;
    if (is_t_dir_int(str[1], all) == -1 && is_t_dir_lab(str[1], all) == -1
    && is_indir_label(str[1], all) == -1 && is_indir_num(str[1], all) == -1
    && is_registre(str[1], all))
        return -1;
    if (is_t_dir_int(str[2], all) == -1 && is_t_dir_lab(str[2], all) == -1
    && is_registre(str[2], all) == -1)
        return -1;
    if (is_registre(str[3], all) != 0)
        return -1;
    return 0;
}
