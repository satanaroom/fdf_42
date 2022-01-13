#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (NULL == s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (start >= s_len || !len)
		return (ft_calloc(1, sizeof(char)));
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (NULL == sub)
		return (NULL);
	while (s[start + i] && (i < len))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
