##
## EPITECH PROJECT, 2019
## PSU_minishell2_2018
## File description:
## Makefile
##

CC		= 		gcc

RM 		=		rm -rf

SRC		=		src/main.c						\
				src/basic_tools.c				\
				src/get_path.c					\
				src/str_to_tab/str_to_word_tab.c\
				src/str_to_tab/fill_tab.c		\
				src/short_command.c				\
				src/my_strcat.c					\
				src/execute_cmd.c				\
				src/rm_return_line.c			\
				src/env.c						\
				src/exit.c						\
				src/cd.c						\
				src/clear_line.c				\
				src/env/env.c

CFLAGS	=		-I./include

OBJ		=		$(SRC:.c=.o)

NAME	=		mysh

all: $(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean all
