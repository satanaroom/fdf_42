#include "get_next_line.h"

char	*ft_start_loop(int fd, t_lines *ln, t_statics *st)
{
	long	count;

	while (st->count_lines == 0 || st->buff[st->i] != '\n')
	{
		if (st->buff[st->i] == '\0')
		{
			count = read(fd, st->buff, BUFFER_SIZE);
			if (count <= 0)
			{
				if (ln->line[0])
					return (ln->line);
				free(ln->line);
				return (NULL);
			}
			st->buff[count] = '\0';
			st->i = 0;
		}
		st->j = 0;
		ln->line2 = ft_create_second_line(ln, st);
		ln->line = ft_create_third_line(ln, st);
	}
	return (ln->line);
}

char	*get_next_line(int fd)
{
	static t_statics	st;
	t_lines				ln;

	st.j = 0;
	ln.line = ft_create_new_line(fd, &ln, &st);
	if (NULL == ln.line)
		return (NULL);
	ln.line = ft_start_loop(fd, &ln, &st);
	if (NULL == ln.line)
		return (NULL);
	if (st.j == 0 && st.buff[st.i] == '\n')
	{
		free(ln.line);
		ln.line = (char *)malloc(sizeof(char) * 2);
		ln.line[0] = '\n';
		ln.line[1] = '\0';
	}
	if (ln.line[0])
		return (ln.line);
	free(ln.line);
	return (NULL);
}
