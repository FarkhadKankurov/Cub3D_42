#include "../includes//libft.h"
#include "../includes/map_struct.h"

void	check_line(int line)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(g_map->map[line]))
	{
		if (g_map->map[line][i] == '1' || g_map->map[line][i] == ' ')
			continue;
		else
			close_find_player("Error\nFailed to read map");
	}
}

void	check_zeros(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_map->num_of_strings)
	{
		if (i == 0)
		{
			check_line(0);
			i++;
			continue;
		}
		if (i == g_map->num_of_strings - 1)
			check_line(g_map->num_of_strings - 1);
		j = 0;
		while (j < (int)ft_strlen(g_map->map[i]))
		{
			if (g_map->map[i][j] == '0' || g_map->map[i][j] == '2')
				check_open_spaces(i, j);
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (y == -1)
	{
		write(2, "Map Error\n", 11);
		free_two_dim_array(map, g_map->num_of_strings + 1);
		exit(0);
	}
	if (map[y][x] == ' ')
	{
		write(2, "Map Error\n", 11);
		free_two_dim_array(map, g_map->num_of_strings + 1);
		exit(0);
	}
	if (map[y][x] == '1' || map[y][x] == '.')
		return ;
	map[y][x] = '.';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	check_all(char *argv)
{
	char	*str;
	int		file;
	t_list	*head;

	head = NULL;
	file = open(argv, O_RDONLY);
	if (file == -1)
		check_open("Error\nFailed to open file");
	head = loop(file, &str);
	if (*str == '\0')
		close_all_with_list(file, &str, head);
	close(file);
	ft_lstadd_back(&head, ft_lstnew(str));
	g_map->num_of_strings = ft_lstsize(head);
	make_map(head, g_map->num_of_strings);
}

int		start(int argc, char **argv)
{
	g_map = malloc(sizeof(t_map));
	g_flag = malloc(sizeof(t_flag));
	g_hero = malloc(sizeof(t_hero));
	g_sprite = malloc(sizeof(t_sprite));
	g_flag->ceil_color = 0;
	g_flag->floor_color = 0;
	g_flag->path_north = 0;
	g_flag->path_south = 0;
	g_flag->path_east = 0;
	g_flag->path_west = 0;
	g_flag->path_sprite = 0;
	g_flag->resolution = 0;
	g_flag->save = 0;
	validate_argc(argc, argv);
	check_all(argv[1]);
	find_num_of_sprites();
	return (1);
}
