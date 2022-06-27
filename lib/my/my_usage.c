/*
** EPITECH PROJECT, 2022
** my_usage
** File description:
** my_usage
*/

#include "my.h"

void my_usage(int ac, char **av, char *path)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        my_print_file(path);
}
