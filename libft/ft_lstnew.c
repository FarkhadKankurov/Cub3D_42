#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ret->content = content;
	ret->next = 0;
	return (ret);
}
