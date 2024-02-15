##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for LS
##

NAME	=	libmy.a

SRCS	=	analyse_events.c \
			my_putchar.c \
			my_put_nbr.c \
			my_putstr.c \
			manage_mouse_click.c \
			move_rect.c \
			my_strcmp.c \
			my_strlen.c \
			information.c \
			init.c \
			destroyer.c \
			enem_sprite.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	cp my.h ../../include/
	cp $(NAME) ../

clean:
	rm -f $(OBJS)
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)

re:	fclean all
