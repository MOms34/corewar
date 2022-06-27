/*
** EPITECH PROJECT, 2022
** main_for_asm
** File description:
** main_for_asm
*/

#include "my.h"
#include "asm.h"


char **recupe(asm_t *all, int i)
{
    char **str = NULL;
    char *split = malloc(sizeof(char) * 5);

    split[0] = '"';
    split[1] = ' ';
    split[2] = '\n';
    split[3] = '\t';
    split[3] = '\0';
    str = parse_r(all->file[i], split);
    return str;
}

void check_name(asm_t *all)
{
    all->name = NULL;
    all->comment = NULL;
    int countname = 0;
    int countcomment = 0;

    for (int i = 0; all->file[i] != NULL; i++) {
        if (my_strncmp(all->file[i], NAME_CMD_STRING, 5) == 0) {
            all->name = recupe(all, i);
            countname++;
        }
        if (my_strncmp(all->file[i], COMMENT_CMD_STRING, 8) == 0) {
            all->comment = recupe(all, i);
            countcomment++;
        }
        if (countname > 1 || countcomment > 1) {
            my_putstr("Too many .name or .comment");
            exit(84);
        }
            }
}

void remplircom(asm_t *all, char *comment_f, char *name_f)
{
    char *str = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);

    all->comment_f = comment_f;
    all->name_f = name_f;
    for (int i = 0; i < PROG_NAME_LENGTH + 1; str[i++] = 0);
    my_strcat(str, all->name_f);
    my_strcat(str, ".cor");
    all->namefile = str;
}

void transforme(asm_t *all)
{
    char *str = " ";
    char *name_f = malloc(sizeof(char) * PROG_NAME_LENGTH + 7 );
    char *comment_f = malloc(sizeof(char) * COMMENT_LENGTH + 1);

    for (int i = 0; i < COMMENT_LENGTH + 1; comment_f[i++] = 0);
    for (int i = 0; i < PROG_NAME_LENGTH + 7; name_f[i++] = 0);
    if (all->comment == NULL || all->name == NULL)
        exit(84);
    errorname(all);
    for (int i = 1; all->name[i] != NULL; i++) {
        my_strcat(name_f, all->name[i]);
        if (all->name[i + 1] != NULL)
            my_strcat(name_f, str);
    }
    for (int i = 1; all->comment[i] != NULL; i++) {
         my_strcat(comment_f, all->comment[i]);
        if (all->comment[i + 1] != NULL)
            my_strcat(comment_f, str);
    }
    remplircom(all, comment_f, name_f);
}
