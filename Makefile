##
## EPITECH PROJECT, 2018
## PSU_navy_2018
## File description:
## Makefile-navy
##

SRC	=	src/main.c	\
		src/fonction.c	\
		src/get_map.c	\
		src/sig.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall		\
		-Wextra		\
		-I./include	\

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
