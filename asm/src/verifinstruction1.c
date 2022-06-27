/*
** EPITECH PROJECT, 2022
** main_for_asm
** File description:
** main_for_asm
*/

#include "my.h"
#include "asm.h"

char *split_espace(char *str)
{
    int count = 0;
    int x = 0;
    char *buff = malloc(sizeof(char) * 128);

    for (int i = 0; str[i] != '\0'; i++) {
        if (limitp(str[i], LABEL_CHARS) == -1 && count == 0)
            count++;
        if (count > 0) {
            buff[x] = str[i];
            x++;
        }
        if (count > 0 && str[i + 1] == '\0')
            buff[x] = '\0';
    }
    return buff;
}

char *change_my_string(char *str, char c)
{
    char *buf = malloc(sizeof(char) * (my_strlen(str) + 2));

    for (int i = 0; str[i] != '\0'; i++) {
        buf[i] = str[i];
        if (str[i + 1] == '\0') {
            buf[i + 1] = c;
            buf[i + 2] = '\0';
        }
    }
    return buf;
}
list *tab_instruc_list(asm_t *all, list *L)
{
    char **cmd = NULL;

    L = NULL;

    for (int i = 0; all->instruct->instr[i] != NULL; i++) {
        all->instruct->instr[i] = change_my_string(all->instruct->\
        instr[i], ',');
        cmd = parse_r(all->instruct->instr[i], " ,\t");
        L = addAt(L, cmd, i);
        cmd = NULL;
    }
    return L;
}
char *split_label(char *str)
{
    char *temp = malloc(sizeof(char) * 128);
    char **buffer = NULL;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        temp[i] = str[i];
        if (str[i + 1] == '\0') {
            temp[i + 1] = '<';
            temp[i + 2] = '\0';
        }
    }
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == ':' && count == 0) {
            temp[i] = '<';
            count++;
        }
    }
    buffer = parse_r(temp, "<");
    if (buffer[1] == NULL)
        return str;
    if (buffer[1][0] == ' ' || buffer[1][0] == '\t')
        buffer[1] = split_espace(buffer[1]);
    return buffer[1];
}
void my_instr_creat(asm_t *all)
{
    int x = 0;
    char *buff = NULL;

    all->instruct->instr = malloc(sizeof(char *) * (all->instruct->lenght + 1));
    for (int i = 0; i < all->instruct->lenght + 1; i++) {
        all->instruct->instr[i] = malloc(sizeof(char) * (COMMENT_LENGTH ));
        for (int j = 0; j < COMMENT_LENGTH; all->instruct->instr[i][j++] =0);
    }
    for (int i = all->instruct->i; all->file[i] != NULL; i++) {
        all->instruct->instr[x] = all->file[i];
        x++;
        if (all->file[i + 1] == NULL) {
            all->instruct->instr[x] = NULL;
            break;
        }
    }
    for (int i = 0; all->instruct->instr[i]; i++) {
        for (int j = 0; op_tab[j].mnemonique; j++) {
            if (my_strncmp(op_tab[j].mnemonique, all->instruct->instr[i], (my_strlen(op_tab[j].mnemonique))) == 0 && all->instruct->instr[i][my_strlen(op_tab[j].mnemonique)] == ' ')
                break;
            if (my_strncmp(op_tab[j].mnemonique, all->instruct->instr[i], (my_strlen(op_tab[j].mnemonique))) == 0) {
                all->instruct->instr[i]= split_label(all->instruct->instr[i]);
            }
            if (my_strncmp(op_tab[j].mnemonique, all->instruct->instr[i], (my_strlen(op_tab[j].mnemonique))) != 0 && op_tab[j + 1].mnemonique == NULL) {
                all->instruct->instr[i] = split_label(all->instruct->instr[i]);

            }
        }
    }
}
