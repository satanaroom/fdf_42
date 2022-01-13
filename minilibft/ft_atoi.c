#include "libft.h"

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	if (num > 9223372036854775807 && sign == -1)
		return (0);
	if (num > 9223372036854775807)
		return (-1);
	return ((int)num * sign);
}
