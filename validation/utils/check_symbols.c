#include "../../includes/cub.h"
#include "../../includes/map_struct.h"

int		check_symbol(char c)
{
	return (c == '0' || c == '2');
}

int		check_empty_symbol(char c)
{
	return (c == '\0' || c == ' ');
}

int		is_space(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

int		validate_map_chars(int i, int j)
{
	return (g_map->map[i][j] == 'N' ||
	g_map->map[i][j] == 'S' ||
	g_map->map[i][j] == 'E' ||
	g_map->map[i][j] == 'W' ||
	g_map->map[i][j] == '1' ||
	g_map->map[i][j] == '2' ||
	g_map->map[i][j] == '0' ||
	g_map->map[i][j] == ' ');
}

void	check_open_spaces(int i, int j)
{
	if (i >= 1 && i < g_map->num_of_strings - 1)
		if (j > (int)ft_strlen(g_map->map[i - 1]) ||
				j > (int)ft_strlen(g_map->map[i + 1]))
			close_find_player("Error\nFailed to read map");
	if (check_empty_symbol(g_map->map[i - 1][j]) ||
		check_empty_symbol(g_map->map[i + 1][j]) ||
		check_empty_symbol(g_map->map[i][j + 1]) ||
		check_empty_symbol(g_map->map[i][j - 1]))
		close_find_player("Error\nFailed to read map");
	if (check_symbol(g_map->map[i - 1][j]) ||
		check_symbol(g_map->map[i + 1][j]) ||
		check_symbol(g_map->map[i][j - 1]) ||
		check_symbol(g_map->map[i][j + 1]))
		if (check_empty_symbol(g_map->map[i - 1][j]) ||
			check_empty_symbol(g_map->map[i + 1][j]) ||
			check_empty_symbol(g_map->map[i][j + 1]) ||
			check_empty_symbol(g_map->map[i][j - 1]))
			close_find_player("Error\nFailed to read map");
}
