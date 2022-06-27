/*
** EPITECH PROJECT, 2022
** asm
** File description:
** corewar
*/

#include "asm.h"
#include "my.h"

int compt_limit(char *raw_cmd, char *limit)
{
    int c = my_strlen(limit);
    int a = 0;
    int b = 0;
    int y = 0;

    while (raw_cmd[a] != '\0') {
        while (b < c) {
            if (limit[b] == raw_cmd[a]) {
                y++;
            }
            b++;
        }
        a++;
        b = 0;
    }
    return y;
}

int check_size(char *raw_cmd, char *limit)
{
    int a = 0;
    int b = 0;
    int compt = 1;
    int compt1 = 0;

    while (raw_cmd[a] != '\0') {
        while (b < my_strlen(limit)) {
            if (limit[b] == raw_cmd[a]) {
                compt -= 1;
                if (compt > compt1) {
                    compt1 = compt;
                    compt = 0;
                }
                if (compt < compt1)
                    compt = 0;
            }
            b++;
        }
        b = 0;
        a++;
        compt++;
    }
    return (compt1);
}

int count_word(char *str, char *limit)
{
    int z = 0;
    int count = 0;

    if (z == 0 && limitp(str[z], limit) == -1) {
        while (limitp(str[z], limit) != -1)
            z++;
    }
    while (str[z] != '\0') {
        while ( limitp(str[z], limit) != -1) {
            if (str[z] == '\0') {
                count++;
                break;
            }
            if (limitp(str[z], limit) == 0)
                z++;
            if (limitp(str[z], limit) == -1 )
                count++;
        }
        if (limitp(str[z], limit) == -1)
            z++;
    }
    return (count);
}

char **parse(char *raw_cmd, char *limit)
{
    char **cmd = NULL;
    int i = count_word(raw_cmd, limit);
    int compt = 0;
    int compt1 = check_size(raw_cmd, limit);

    cmd = malloc(sizeof(char *) * (i + 1));
    while (compt < i + 1) {
        cmd[compt] = malloc(sizeof(char) * (compt1 + 1));
        compt += 1;
    }
    cmd[--compt] = NULL;
    return (cmd);
}

char **parse_r(char *raw_cmd, char *limit)
{
    char **cmd = parse(raw_cmd, limit);
    int a = 0;
    int c = 0;
    int d = 0;

    while (raw_cmd[a] != '\0') {
        while (limitp(raw_cmd[a], limit) != -1 && raw_cmd[a] != '\0') {
            if (limitp(raw_cmd[a], limit) == 0){
                cmd[d][c] = raw_cmd[a];
                c++;
                a++;
            }
            if (limitp(raw_cmd[a], limit) == -1) {
                cmd[d][c] = '\0';
                d++;
                c = 0;
            }
        }
        while (limitp(raw_cmd[a], limit) != 0)
            a++;
    }
    cmd[d] = NULL;
    return (cmd);
}
