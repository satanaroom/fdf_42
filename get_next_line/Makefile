NAME	=	get_next_line.a

SRCS	=	get_next_line.c get_next_line_utils.c
HEADER	=	get_next_line.h
OBJS	=	$(SRCS:%.c=%.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
REMOVE	=	rm -f

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(REMOVE) $(OBJS)

fclean	:	clean
			$(REMOVE) $(NAME)

re		:	fclean all
