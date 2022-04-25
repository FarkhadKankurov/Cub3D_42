#include "../../includes/cub.h"

void	check_open(char *err_msg)
{
	write(1, err_msg, ft_strlen(err_msg));
	free(g_map);
	free(g_flag);
	free(g_hero);
	free(g_sprite);
	exit(0);
}

void	check_game_params(char *str, int file)
{
	close(file);
	write(1, "Error\nFailed to read map arguments", 35);
	free(g_map);
	free(g_flag);
	free(g_hero);
	free(str);
	free(g_sprite);
	exit(0);
}

void	close_all_with_list(int file, char **str, t_list *head)
{
	write(1, "Error\nFailed to read map", 25);
	close(file);
	free(g_map);
	free(g_flag);
	free(g_hero);
	free(g_sprite);
	free(*str);
	content_clear(head);
	list_clear(head);
	exit(0);
}

void	calloc_error(t_list *head)
{
	write(1, "Error\nMalloc error", 19);
	list_clear(head);
	content_clear(head);
	free(g_map);
	free(g_flag);
	free(g_hero);
	free(g_sprite);
	exit(0);
}

void	close_find_player(char *err_msg)
{
	write(1, err_msg, ft_strlen(err_msg));
	free_two_dim_array(g_map->map, g_map->num_of_strings);
	free(g_map->path_sprite);
	free(g_map->path_south);
	free(g_map->path_north);
	free(g_map->path_west);
	free(g_map->path_east);
	free(g_map);
	free(g_flag);
	free(g_hero);
	free(g_sprite);
	exit(0);
}
