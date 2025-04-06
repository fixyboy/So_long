FUNC = ft_functions.c ft_functions2.c ft_printf.c

SRCS = ${FUNC}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar -rsc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
