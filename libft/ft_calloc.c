#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	s_size;

	s_size = count * size;
	s = malloc(s_size);
	if (NULL == s)
		return (NULL);
	ft_bzero(s, s_size);
	return (s);
}
