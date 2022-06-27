/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** File Header
*/

#include "my.h"
#include "asm.h"

list *creatcell(char **instruct)
{
    list *list = malloc(sizeof(list));

    if (!list)
        return NULL;
    list->instruct = instruct;
    list->hexa = instruct;
    list->next = NULL;
    return list;
}

int isemptylist(list *L)
{
    return L == NULL;
}
