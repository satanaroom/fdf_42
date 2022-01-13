#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	while ((*s1 || *s2) && num--)
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}