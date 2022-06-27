/*
** EPITECH PROJECT, 2022
** error
** File description:
** asm
*/

#include "my.h"
#include "asm.h"

void errorname(asm_t *all)
{
    if (all->name[1] == NULL || all->name[2] != NULL) {
        my_putstr("Error in your .name");
        exit(84);
    }
    if (all->comment[1] == NULL) {
        my_putstr("Error in your .comment");
        exit(84);
    }
}