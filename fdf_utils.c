#include "fdf.h"

void	ft_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

size_t	ft_word_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			++count;
			while (str[i] && str[i] != c)
				++i;
			if (!str[i])
				return (count);
		}
		i++;
	}
	return (count);
}
