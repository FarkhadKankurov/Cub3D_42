#include "../../includes/cub.h"

void		find_player(void)
{
	int i;
	int j;

	i = 0;
	g_hero->flag = 0;
	while (g_map->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(g_map->map[i]))
		{
			if (!(validate_map_chars(i, j)))
				close_find_player("Error\nFailed to read hero pos");
			init_hero_pos(i, j);
			j++;
		}
		i++;
	}
	if (g_hero->flag == 0)
		close_find_player("Error\nFailed to read hero pos");
	make_copy();
}

void		init_hero_pos(int i, int j)
{
	if (g_map->map[i][j] == 'N' || g_map->map[i][j] == 'S' ||
		g_map->map[i][j] == 'E' || g_map->map[i][j] == 'W')
	{
		if (g_hero->flag != 0)
			close_find_player("Error\nFailed to read hero pos");
		g_hero->pos_y = i;
		g_hero->pos_x = j;
		g_hero->direction = g_map->map[i][j];
		g_map->map[i][j] = '0';
		g_hero->flag = 1;
	}
}

char		**make_map(t_list *head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = 0;
	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		calloc_error(head);
	tmp = head;
	g_map->column = 0;
	while (head)
	{
		map[i] = ft_strdup(head->content);
		g_map->column = g_map->column > ft_strlen(head->content) ?
						g_map->column : ft_strlen(head->content);
		free(head->content);
		head = head->next;
		i++;
	}
	list_clear(tmp);
	g_map->map = map;
	find_player();
	return (map);
}

int			make_copy(void)
{
	int		i;
	char	**map;
	int		column;
	int		strings;

	if (!(map = (char **)malloc((sizeof(char *) * g_map->num_of_strings + 1))))
		close_find_player("Error\nMalloc error");
	i = -1;
	strings = g_map->num_of_strings + 1;
	column = (int)g_map->column + 2;
	while (++i < strings)
	{
		map[i] = ft_calloc(1, column + 1);
		ft_memset(map[i], ' ', column);
		if (i < g_map->num_of_strings)
			ft_strlcpy(map[i] + 1, g_map->map[i], column - 1);
	}
	check_zeros();
	flood_fill(map, g_hero->pos_x + 1, g_hero->pos_y);
	free_two_dim_array(map, g_map->num_of_strings + 1);
	return (1);
}
