##
## EPITECH PROJECT, 2023
## Make makefile
## File description:
## Make for LS
##

NAME	=	my_hunter

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS = -Werror -Wall -Wextra

LDLFLAGS = -L ./lib/my/ -lmy

CODING = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/my -f Makefile all
	$(CC) -o $(NAME) $(OBJS) $(LDLFLAGS) $(CODING)

clean:
		rm -f $(NAME)
		$(MAKE) -C ./lib/my clean

fclean: clean
		rm  -f $(OBJS)
		$(MAKE) -C ./lib/my fclean

re: fclean all
