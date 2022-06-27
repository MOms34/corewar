##
## EPITECH PROJECT, 2022
## makefile_for_corewar
## File description:
## makefile_for_corewar
##

CC			= 	gcc

NAME		= 	asm

CFLAGS		=  	-W -Wall  -Wextra  -g3

LIBS		=	-lmy

CPPFLAGS	=	-I../include/

SRC 		=	$(shell find ./ -name "*.c")

OBJ 		= 	$(SRC:.c=.o)

all			: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib
	$(CC) -o $(NAME) $(OBJ) -L../lib $(LIBS) -g3
	@echo "Build OK"

clean :
	make clean -C ../lib
	$(RM) $(OBJ)

fclean : clean
	make fclean -C ../lib
	$(RM) $(NAME)

re : fclean all