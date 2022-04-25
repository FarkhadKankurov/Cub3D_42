#include "../../includes/cub.h"

void	content_clear(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		list = tmp;
	}
}

void	list_clear(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void	free_two_dim_array(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
