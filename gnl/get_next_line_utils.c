#include "get_next_line.h"

char	*ft_create_new_line(int fd, t_lines *ln, t_statics *st)
{
	if (read(fd, st->buff, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ln->line = (char *)malloc(sizeof(char) * 1);
	if (NULL == ln->line)
		return (NULL);
	ln->line[0] = '\0';
	if (st->buff[st->i] == '\n')
		st->i++;
	return (ln->line);
}

char	*ft_create_second_line(t_lines *ln, t_statics *st)
{
	while (st->buff[st->i + st->j] && st->buff[st->i + st->j] != '\n')
		st->j++;
	ln->line2 = (char *)malloc(sizeof(char) * (st->j + 1
				+ (st->buff[st->i + st->j] == '\n')));
	if (NULL == ln->line2)
	{
		if (ln->line[0])
			return (ln->line);
		free(ln->line);
		return (NULL);
	}
	st->j = 0;
	return (ln->line2);
}

char	*ft_create_third_line(t_lines *ln, t_statics *st)
{
	while (st->buff[st->i] && st->buff[st->i] != '\n')
	{
		ln->line2[st->j] = st->buff[st->i];
		st->i++;
		st->j++;
	}
	if (st->buff[st->i] == '\n')
	{
		st->count_lines++;
		ln->line2[st->j++] = '\n';
	}
	ln->line2[st->j] = '\0';
	ln->line3 = ft_strjoin(ln->line, ln->line2);
	free(ln->line);
	free(ln->line2);
	ln->line = ln->line3;
	return (ln->line);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (NULL == s1 || NULL == s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (NULL == str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
