##
## EPITECH PROJECT, 2020
## STRACE
## File description:
## makefile
##

CC = gcc

RM = rm

CFLAGS += -Wall -Werror
CFLAGS += -I.

NAME = myftp

SRCS =  main.c \
		display.c \
		ftp.c \
		my_str_array.c \
		manage.c \
		command/user.c \
		command/quit.c \
		command/pass.c \
		command/pwd.c \
		command/help.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 