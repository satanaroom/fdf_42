#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (NULL == dst && NULL == src)
		return (dst);
	while (i < n)
	{
		*d++ = *s++;
		i++;
	}
	return (dst);
}
