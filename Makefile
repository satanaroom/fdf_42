NAME		=	fdf

SRCS		=	fdf.c src/utils.c src/parser.c\
				src/draw.c src/init.c src/isometric.c\
				src/key_handler.c
HEADER		=	fdf.h
OBJS		=	$(SRCS:%.c=%.o)
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
REMOVE		=	rm -f
LIBFT		=	-L. minilibft/minilibft.a
GNL			=	-L. gnl/get_next_line.a
MLX			=	libmlx.dylib -framework OpenGL -framework AppKit

.PHONY		:	all clean libftclean gnlclean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C minilibft
				make -C gnl
				make -C mlx
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(MLX)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS) libmlx.dylib

libftclean	:
				make fclean -C minilibft

gnlclean	:
				make fclean -C gnl

mlxclean	:
				make clean -C mlx

fclean		:	clean libftclean gnlclean mlxclean
				$(RM) $(NAME)

re			:	fclean all

