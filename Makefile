SRCS =	GNL/get_next_line_utils.c\
		GNL/get_next_line.c\
		srcs/bord_parsing.c\
		srcs/so_long.c\
		srcs/move.c\
		srcs/build_map.c\
		srcs/make_image.c\
		srcs/check_map.c\
		srcs/free_map.c\
		srcs/functions.c\
		srcs/parsing.c\
		srcs/game.c\
		srcs/flood_fill.c\


CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -g3

OBJS	=	$(SRCS:.c=.o)


NAME	=	so_long

INCL	= -I. -I/usr/include -Imlx -Ilibft
MFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib
MLX		= mlx/libmlx_Linux.a

PRINTF	=	printf/libftprintf.a

all: ${NAME}

$(NAME): $(OBJS) $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MFLAGS) $(PRINTF) -o $(NAME) 
 

$(PRINTF):
	make -C printf

$(MLX):
	make -C mlx
	
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I. -c $< -o $@ $(INCL)

clean:
		rm -f ${OBJS}
		make -C printf clean
		make -C mlx clean

fclean: clean
		rm -f $(NAME)
		make -C printf fclean

re:		fclean all

.PHONY: all clean fclean re/