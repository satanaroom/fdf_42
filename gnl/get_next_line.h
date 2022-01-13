#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_statics
{
	char	buff[BUFFER_SIZE * (2 * (BUFFER_SIZE > 0) - 1) + 1];
	int		count_lines;
	int		i;
	int		j;
}			t_statics;

typedef struct s_lines
{
	char	*line;
	char	*line2;
	char	*line3;
}			t_lines;

char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_create_new_line(int fd, t_lines *ln, t_statics *st);
char			*ft_create_second_line(t_lines *ln, t_statics *st);
char			*ft_create_third_line(t_lines *ln, t_statics *st);

#endif
