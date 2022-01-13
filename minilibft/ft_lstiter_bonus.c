#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (NULL != lst)
	{
		while (NULL != lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
