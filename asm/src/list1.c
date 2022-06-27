/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** File Header
*/

#include "my.h"
#include "asm.h"

list *addAt(list *L, char **instruct, int pos)
{
    list *prec = L;
    list *cur = L;
    int i = 0;

    list *list = creatcell(instruct);
    if (isemptylist(L))
        return list;
    if (pos == 0) {
        list->next = L;
        return list;
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = list;
    list->next = cur;
    return L;
}

list *freelist(list *L)
{
    list *tmp = NULL;

    while (L) {
        tmp = L->next;
        free(L);
        L = tmp;
    }
    return L;
}

void printlist(list *L, asm_t *all)
{
    int z = 0;
    int count = 0;
    while (L) {
        for(int i = 0; L->instruct[i] != NULL; i++) {
            for (int j = 0; op_tab[j].mnemonique; j++) {
                if (my_strncmp(op_tab[j].mnemonique, L->instruct[i],
                 (my_strlen(op_tab[j].mnemonique))) == 0 && my_strlen
                 (op_tab[j].mnemonique) == my_strlen(L->instruct[i]) && j == 0) {
                    count++;
                }

                if (my_strncmp(op_tab[j].mnemonique, L->instruct[i],
                 (my_strlen(op_tab[j].mnemonique))) == 0 && my_strlen
                 (op_tab[j].mnemonique) == my_strlen(L->instruct[i])) {
                    z = check_arg_liste(L->instruct, all);
                }
            }
            if (z == -1) {
                my_putstr("Error instructions.");
                exit(84);
            }
        }
        L = L->next;
    }
}