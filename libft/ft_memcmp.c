#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*d1 == *d2 && --n)
	{
		d1++;
		d2++;
	}
	return ((int)(*d1 - *d2));
}
