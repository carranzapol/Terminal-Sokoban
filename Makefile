##
## EPITECH PROJECT, 2023
## cpool_makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c) \
        $(wildcard lib/my/*.c) \
        $(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban
CFLAGS	=	-I./include/ -g3
LDFLAGS = -lncurses

all:        $(NAME)

$(NAME):	lib $(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

lib:
		make -C lib/my/
clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all
