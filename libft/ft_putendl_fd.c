#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (NULL != s)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
	write(fd, "\n", 1);
}
