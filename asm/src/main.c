/*
** EPITECH PROJECT, 2022
** main_for_asm
** File description:
** main_for_asm
*/

#include "my.h"
#include "asm.h"

instr_t *init_instruct(void)
{
    instr_t *instruct = malloc(sizeof(instr_t));
    instruct->lenght = 0;
    instruct->words_instr = 0;
    instruct->lenght = 0;
    instruct->instr = NULL;
    return instruct;
}

void init_file(asm_t *all, char **argv)
{
    char *buffer = my_open_file(argv[1]);

    all->instruct = init_instruct();
    all->buf = buffer;
    all->file = parse_r(all->buf, "\n\0");
    all->champ_s = 0;
}

void creat_myfile(asm_t *all)
{
    int fd = open(all->namefile, O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd == -1)
        exit(84);
    write(fd, &all->magic, sizeof(all->magic));
    write(fd, all->name_f, PROG_NAME_LENGTH + 7);
    write(fd, &all->champ_s, 1);
    write(fd, all->comment_f, COMMENT_LENGTH + 1);
    close(fd);
}

int main(int ac, char **av)
{
    asm_t *all = malloc(sizeof(asm_t));
    list *list = NULL;
    all->magic= convert(COREWAR_EXEC_MAGIC);

    my_usage(ac, av, "asm/data/usage_asm.txt");
    init_file(all, av);
    check_name(all);
    transforme(all);
    labelstr(all);
    list = tab_instruc_list(all, list);
    printlist(list, all);
    creat_myfile(all);
    return 0;
}
