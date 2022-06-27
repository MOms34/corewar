##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

all				:
				make -C corewar
				make -C asm

clean_corewar	:
				make clean -C corewar/
				make clean -C asm

fclean_corewar	:
				make fclean -C corewar/
				make fclean -C asm

re_corewar		:
				make re -C corewar/
				make re -C asm

clean			:
				make clean -C corewar
				make clean -C asm
				
fclean			:
				make fclean -C corewar
				make fclean -C asm

re				: fclean all