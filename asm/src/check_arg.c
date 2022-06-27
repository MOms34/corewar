/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"


int check_arg_liste(char **str, asm_t *all)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i][0] == '#') {
            str[i] = NULL;
            count++;
        }
        if (count != 0)
            str[i] = NULL;
    }
    if (strcmp(str[0], "live") == 0)
        return check_live(str, all);
    if (strcmp(str[0], "ld") == 0)
        return check_ld(str, all);
    if (strcmp(str[0], "st") == 0)
        return check_st(str, all);
    if (strcmp(str[0], "add") == 0)
        return check_add(str, all);
    if (strcmp(str[0], "sub") == 0)
        return check_sup(str, all);
    if (strcmp(str[0], "and") == 0)
        return check_and(str, all);
    return check_arg_liste1(str, all);
}

int check_arg_liste1(char **str, asm_t *all)
{
    if (strcmp(str[0], "or") == 0)
        return check_or(str, all);
    if (strcmp(str[0], "xor") == 0)
        return check_xor(str, all);
    if (strcmp(str[0], "zjmp") == 0)
        return check_zjump(str, all);
    if (strcmp(str[0], "ldi") == 0)
        return check_ldi(str, all);
    if (strcmp(str[0], "sti") == 0)
        return check_sti(str, all);
    if (strcmp(str[0], "fork") == 0)
        return check_fork(str, all);
    if (strcmp(str[0], "lld") == 0)
        return check_lld(str, all);
    if (strcmp(str[0], "lldi") == 0)
        return check_lldi(str, all);
    if (strcmp(str[0], "lfork") == 0)
        return check_lfork(str, all);
    if (strcmp(str[0], "aff") == 0)
        return check_aff(str, all);
    return -1;
}
