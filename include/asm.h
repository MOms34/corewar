/*
** EPITECH PROJECT, 2022
** lib_for_asm
** File description:
** lib_for_asm
*/

#ifndef ASM_H
    #define ASM_H

    #define ERROR 84
    #define SUCCESS 0
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <time.h>
    #include <pwd.h>
    #include <stdbool.h>
    #include <grp.h>

#define MEM_SIZE (6*1024)
#define IDX_MOD 512
#define MAX_ARGS_NUMBER 4
#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','
#define STRTWTB " ,\t\n\"'"
#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"
#define REG_NUMBER 16
#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8
#define IND_SIZE 2
#define REG_SIZE 4
#define DIR_SIZE REG_SIZE
#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048
#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40
#define COREWAR_EXEC_MAGIC 0xea83f3

typedef char args_type_t;
typedef struct 	op_s op_t;
typedef struct 	header_s t_header;

typedef struct s_corarg
{
    char *value;
    int type;
} t_corarg;

typedef struct s_corline
{
    char *label;
    char *instruction;
    char **args;
    int nbr;
    int mempos;
    t_corarg *tab_args;
    struct s_corline *next;
    struct s_corline *prev;
} t_corline;

typedef struct s_corlabel
{
    int mempos;
    char *name;
    struct s_corlabel *next;
} t_corlabel;

typedef struct s_cor
{
    int fd;
    char *name;
    char **tab;
    t_corline *first_line;
    t_corlabel *first_label;
} t_cor;

typedef struct header_s
{
    int magic;
    char prog_name[PROG_NAME_LENGTH+1];
    int prog_size;
    char comment[COMMENT_LENGTH+1];
} header_t;

struct op_s
{
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
};

typedef union u_int4char
{
    int nbr;
    unsigned char str[4];
} t_int4char;

typedef union u_int2char
{
    int nbr;
    unsigned char str[2];
} t_int2char;

typedef union u_intchar
{
    int nbr;
    unsigned char str;
}                       	t_intchar;

extern op_t op_tab[];

typedef struct instr_s {
    int words_instr;
    int i;
    int lenght;
    char **instr;
} instr_t;

typedef struct cell_t
{
    char **instruct;
    char **hexa;
    struct cell_t *next;
} list;

typedef struct asm_s {
    char **file;
    char *buf;
    char **name;
    char **comment;
    char *name_f;
    char *comment_f;
    char *namefile;
    int magic;
    bool bname;
    bool bcomment;
    int champ_s;
    instr_t *instruct;
} asm_t;

int compt_limit(char *raw_cmd, char *limit);
int check_size(char *raw_cmd, char *limit);
int count_word(char *str, char *limit);
char **parse(char *raw_cmd, char *limit);
char **parse_r(char *raw_cmd, char *limit);
char **recupe(asm_t *all, int i);
void check_name(asm_t *all);
void transforme(asm_t *all);
int my_magic(int data);
int convert(int data);
int limitp(char a, char *limit);
void labelstr(asm_t *all);
void errorname(asm_t *all);
int isemptylist(list *L);
list *creatcell(char **instruct);
list *freelist(list *L);
void printlist(list *L, asm_t *all);
list *addAt(list *L, char **instruct, int pos);
list *tab_instruc_list(asm_t *all, list *L);
int is_digit(char c, asm_t *all);
int is_t_dir_int(char *str, asm_t *all);
int is_label(char c, asm_t *all);
int is_t_dir_lab(char *str, asm_t *all);
int is_indir_num(char *str, asm_t *all);
int is_indir_label(char *str, asm_t *all);
int is_registre(char *str, asm_t *all);
int check_arg_liste(char **str, asm_t *all);
int check_arg_liste1(char **str, asm_t *all);
int check_live(char **str, asm_t *all);
int check_ld(char **str, asm_t *all);
int check_st(char **str, asm_t *all);
int check_add(char **str, asm_t *all);
int check_sup(char **str, asm_t *all);
int check_and(char **str, asm_t *all);
int check_or(char **str, asm_t *all);
int check_xor(char **str, asm_t *all);
int check_zjump(char **str, asm_t *all);
int check_ldi(char **str, asm_t *all);
int check_sti(char **str, asm_t *all);
int check_fork(char **str, asm_t *all);
int check_lld(char **str, asm_t *all);
int check_lldi(char **str, asm_t *all);
int check_lfork(char **str, asm_t *all);
int check_aff(char **str, asm_t *all);


#endif
