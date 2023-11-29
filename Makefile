##
## EPITECH PROJECT, 2023
## Project
## File description:
## Makefile
##

SRC	=	myhunter.c	\
		game.c	\
		utils.c	\
		event_utils.c	\
		framebuffer_utils.c	\
		background.c	\
		chicken.c	\
		crosshair.c	\

NAME	=	my_hunter

OBJ	=	$(SRC:.c=.o)

CFLAGS += -I./include/ -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/my_printf/
	make -C lib/linked_list/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -L./lib/my_printf	\
	-lmy_printf -L./lib/linked_list -llinked_list -l csfml-graphics	\
	-l csfml-system

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
