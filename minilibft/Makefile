NAME	=	minilibft.a

SRCS	=	ft_atoi.c		ft_bzero.c		ft_calloc.c\
			ft_isalpha.c	ft_isspace.c	ft_memset.c\
			ft_split.c		ft_strlen.c		ft_substr.c

HEADER	= 	minilibft.h
OBJ		=	$(SRCS:%.c=%.o)
OBJ_B	=	$(SRCS_B:%.c=%.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
REMOVE	=	rm -f

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

bonus	:
			make OBJ="$(OBJ_B)" all

clean	:
			$(REMOVE) $(OBJ) $(OBJ_B)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
