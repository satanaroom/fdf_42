#include "libft.h"

static int	ft_len_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*s;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	len = ft_len_count(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (NULL == s)
		return (NULL);
	s[len--] = '\0';
	while (len >= 0)
	{
		s[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
