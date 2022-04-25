#include "../../includes/map_struct.h"
#include "../../includes/cub.h"

int		close_app(void)
{
	free(g_info);
	free(g_text_south);
	free(g_text_north);
	free(g_text_west);
	free(g_text_east);
	free(g_texture);
	free_two_dim_array(g_map->map, g_map->num_of_strings);
	free(g_map->path_east);
	free(g_map->path_west);
	free(g_map->path_north);
	free(g_map->path_south);
	free(g_map->path_sprite);
	free(g_sprite->x);
	free(g_sprite->y);
	free(g_sprite);
	exit(0);
}

int		close_mlx_init(void)
{
	free(g_info);
	free_two_dim_array(g_map->map, g_map->num_of_strings);
	free(g_map);
	free(g_sprite->x);
	free(g_sprite->y);
	free(g_sprite);
	exit(0);
}
