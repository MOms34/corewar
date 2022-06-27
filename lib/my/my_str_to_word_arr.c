/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"

char **my_str_to_word_arr(char *str, char delim)
{
    int word_nb = 1;
    int size = 0;
    char **new;

    for (int i = 0; str[i] != '\0'; i++)
        word_nb += str[i] == delim ? 1 : 0;
    new = malloc(sizeof(char *) * (word_nb + 1));
    if (new == NULL)
        my_put_error("ERROR: Malloc did not work!\n");
    for (int i = 0, j = 0; i < word_nb; i++, j++, size = 0) {
        for (; str[j] != delim && str[j] != '\0'; j++, size++);
        new[i] = malloc(sizeof(char) * (size + 1));
    }
    for (int k = 0, j = 0, i = 0; j < word_nb; j++, i++, k = 0) {
        for (; str[i] != delim && str[i] != '\0'; k++, i++)
            new[j][k] = str[i];
        new[j][k] = '\0';
    }
    new[word_nb] = NULL;
    return new;
}
