/*
** EPITECH PROJECT, 2022
** my_open_file
** File description:
** open_and_read_a_file
*/

#include "my.h"

char *my_open_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    char *buf;

    if (fd == -1)
        my_put_error("ERROR: Wrong path to file!\n");
    if (stat(path, &st) == -1)
        my_put_error("ERROR: Stat did not work!\n");
    buf = malloc(sizeof(char) * (st.st_size + 2));
    if (buf == NULL)
        my_put_error("ERROR: Malloc did not work!\n");
    if ((read(fd, buf, st.st_size)) == -1)
        my_put_error("ERROR: Read did not work!\n");
    buf[st.st_size] = '\n';
    buf[st.st_size + 1] = '\0';
    close(fd);
    return buf;
}

void my_print_file(char *path)
{
    char *buf = my_open_file(path);

    my_putstr(buf);
    free(buf);
}
