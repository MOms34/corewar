/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** corewar asm
*/

#include "my.h"
#include "asm.h"

int is_digit(char c, asm_t *all)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int is_t_dir_int(char *str, asm_t *all)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[0] != '%')
            return -1;
        if (i > 0 && str[1] == '-')
            i++;
        if (i > 0 && is_digit(str[i], all) != 1 )
            return -1;
    }
    all->champ_s += 4;
    return 0;
}

int is_label(char c, asm_t *all)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++) {
        if (c == LABEL_CHARS[i])
            return 1;
    }
    return 0;
}

int is_t_dir_lab(char *str, asm_t *all)
{
    if (str[0] != '%')
            return -1;
    if (str[1] != ':')
            return -1;
    if (str[2] == '\0')
            return -1;
    for (int i = 2; str[i] != '\0'; i++) {
        if (is_label(str[i], all) != 1)
            return -1;
    }
    all->champ_s += 4;
    return 0;
}
