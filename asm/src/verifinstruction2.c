/*
** EPITECH PROJECT, 2022
** main_for_asm
** File description:
** main_for_asm
*/

#include "my.h"
#include "asm.h"

void labelstr(asm_t *all)
{
    int count = 0;
    int max_word = 0;
    int x = 0;

    for (int i = 0; all->file[i] != NULL; i++) {
        if (limitp(all->file[i][0], LABEL_CHARS) == -1) {
            count++;
            max_word = my_strlen(all->file[i]);
        }
        if (limitp(all->file[i][0], LABEL_CHARS) == -1 && x == 0) {
            x = i;
            all->instruct->i = x;
        }
        if (max_word > all->instruct->words_instr)
            all->instruct->words_instr = max_word;
    }
    all->instruct->lenght = count;
    my_instr_creat(all);
}
