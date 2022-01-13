#include "libft.h"

static char	**ft_clear(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_strlen_c(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_word_count(const char *str, char c)
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	char	**array;

	i = 0;
	start = 0;
	if (NULL == s)
		return (NULL);
	array = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (NULL == array)
		return (NULL);
	while (s[i++] == c)
		start++;
	i = -1;
	while (++i < ft_word_count(s, c))
	{
		array[i] = ft_substr(s, start, ft_strlen_c(&s[start], c));
		if (!array[i])
			return (ft_clear(array));
		start += ft_strlen_c(&s[start], c);
		while (s[start] == c)
			start++;
	}
	array[i] = NULL;
	return (array);
}
