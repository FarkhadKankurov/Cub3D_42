#include "../../includes/cub.h"

void	ray_cast(void)
{
	int		x;
	double	*z_buffer;
	double	*sprite_distance;
	int		hit;
	double	camera_x;

	z_buffer = malloc(sizeof(double) * g_map->resolution_x);
	sprite_distance = malloc(sizeof(double) * g_map->num_of_sprites);
	x = 0;
	while (x < g_map->resolution_x)
	{
		hit = 0;
		camera_x = 2 * x / (double)g_map->resolution_x - 1;
		init_struct_params(camera_x);
		calc_hit(&hit);
		move_ray();
		draw_main(x, g_info->ray_len, g_map->side);
		z_buffer[x] = g_info->ray_len;
		x++;
	}
	sort_sprites(sprite_distance);
	draw_sprites(z_buffer);
	free(z_buffer);
	free(sprite_distance);
}
