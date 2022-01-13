NAME		=	fdf

SRCS		=	fdf.c fdf_utils.c get_map.c print_map.c
HEADER		=	fdf.h
OBJS		=	$(SRCS:%.c=%.o)
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
REMOVE		=	rm -f
# MLX_NAME	=	minilibx_mms_20191025_beta
LIBFT		=	-L. minilibft/libft.a
GNL			=	-L. gnl/get_next_line.a
# MLX			=	libmlx.dylib -framework OpenGL -framework AppKit

.PHONY		:	all clean libftclean gnlclean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C minilibft
				make -C gnl
				# make -C mlx
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(MLX)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)
				# libmlx.dylib

libftclean	:
				make fclean -C minilibft

gnlclean	:
				make fclean -C gnl

# mlxclean	:
# 				make clean -C mlx

fclean		:	clean libftclean gnlclean
				$(RM) $(NAME)

re			:	fclean all

