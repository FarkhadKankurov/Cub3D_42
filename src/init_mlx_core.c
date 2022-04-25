#include "../includes/map_struct.h"
#include "../includes/cub.h"

void	check_screen_size(void)
{
	mlx_get_screen_size(g_info->mlx, &g_info->screen_x, &g_info->screen_y);
	if (g_map->resolution_x > g_info->screen_x)
		g_map->resolution_x = g_info->screen_x;
	if (g_map->resolution_y > g_info->screen_y)
		g_map->resolution_y = g_info->screen_y;
	if (g_map->resolution_x <= 0 || g_map->resolution_y <= 0)
	{
		free(g_info);
		free_two_dim_array(g_map->map, g_map->num_of_strings);
		free(g_map);
		exit(0);
	}
}

void	init_mlx_core(void)
{
	g_info = malloc(sizeof(t_info));
	if (!(g_info->mlx = mlx_init()))
		close_mlx_init();
	check_screen_size();
	if (!(g_info->win = mlx_new_window(g_info->mlx, g_map->resolution_x,
					g_map->resolution_y, "cub3D")))
		close_mlx_init();
	if (!(g_info->img = mlx_new_image(g_info->mlx,
					g_map->resolution_x, g_map->resolution_y)))
		close_mlx_init();
	if (!(g_info->addr = mlx_get_data_addr(g_info->img, &g_info->bits_per_pixel,
					&g_info->line_length, &g_info->endian)))
		close_mlx_init();
}
