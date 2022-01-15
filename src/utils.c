#include "../fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_mod(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

size_t	ft_word_count(const char *str, char c)
{
	size_t	count;
	size_t	i;

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
