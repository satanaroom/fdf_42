#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (lst->content != 0)
		(*del)(lst->content);
	free(lst);
}
