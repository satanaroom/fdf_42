#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (NULL != s)
		write(fd, s, ft_strlen(s));
}
