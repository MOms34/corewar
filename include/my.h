/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** my_h
*/

#ifndef MY_H
    #define MY_H

    #include "lib.h"
    #include "corewar.h"
    #include "print.h"

int my_getnbr(char *str);
void my_put_nbr(int nb);
int my_strncmp(const char *s1, const char *s2, int n);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strcmp(char const *str_a, char const *str_b);
int my_strlen(char const *str);
void my_put_error(char *str);
char *my_strcat(char *dest, char const *str);
char **my_str_to_word_arr(char *str, char delim);
char *my_open_file(char *path);
void my_print_file(char *path);
void my_usage(int ac, char **av, char *str);

#endif
