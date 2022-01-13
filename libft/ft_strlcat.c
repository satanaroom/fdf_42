#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	len = i;
	while (src[i - len] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
