NAME		=	fdf

SRCS		=	fdf.c fdf_utils.c get_map.c print_map.c
HEADER		=	fdf.h
OBJS		=	$(SRCS:%.c=%.o)
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
REMOVE		=	rm -f
# MLX_NAME	=	minilibx_mms_20191025_beta
LIBFT		=	-L. libft/libft.a
GNL			=	-L. get_next_line/get_next_line.a
# MLX			=	libmlx.dylib -framework OpenGL -framework AppKit

.PHONY		:	all clean libftclean gnlclean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C libft
				make -C get_next_line
				# make -C $(MLX_NAME)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(MLX)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)
				# libmlx.dylib

libftclean	:
				make fclean -C libft

gnlclean	:
				make fclean -C get_next_line

# mlxclean	:
# 				make clean -C $(MLX_NAME)

fclean		:	clean libftclean gnlclean
				$(RM) $(NAME)

re			:	fclean all

