#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = 0;
	if (f && s)
	{
		out = ft_calloc(1, (ft_strlen(s) + 1));
		if (!out)
			return (NULL);
		while (s[i] != '\0')
		{
			out[i] = f(i, s[i]);
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
