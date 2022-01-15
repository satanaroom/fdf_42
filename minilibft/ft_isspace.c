#include "minilibft.h"

int	ft_isspace(int c)
{
	if ((c == ' ') || (c == '\n') || (c == '\r')
		|| (c == '\t') || (c == '\f') || (c == '\v'))
		return (1);
	else
		return (0);
}
