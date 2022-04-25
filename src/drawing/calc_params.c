#include "../../includes/cub.h"

void		init_struct_params(double camera_x)
{
	g_info->ray_dir_x = g_info->dir_x + g_info->plane_x * camera_x;
	g_info->ray_dir_y = g_info->dir_y + g_info->plane_y * camera_x;
	g_info->map_x = (int)g_info->pos_x;
	g_info->map_y = (int)g_info->pos_y;
	g_info->delta_dist_x = fabs(1 / g_info->ray_dir_x);
	g_info->delta_dist_y = fabs(1 / g_info->ray_dir_y);
	g_info->side_dist_x = calc_side_dist_x(g_info->map_x, g_info->delta_dist_x);
	g_info->side_dist_y = calc_side_dist_y(g_info->map_y, g_info->delta_dist_y);
}

double		calc_side_dist_y(int map_y, double delta_dist_y)
{
	double side_dist_y;

	if (g_info->ray_dir_y < 0)
	{
		g_info->step_y = -1;
		side_dist_y = (g_info->pos_y - map_y) * delta_dist_y;
	}
	else
	{
		g_info->step_y = 1;
		side_dist_y = (map_y + 1.0 - g_info->pos_y) * delta_dist_y;
	}
	return (side_dist_y);
}

double		calc_side_dist_x(int map_x, double delta_dist_x)
{
	double side_dist_x;

	if (g_info->ray_dir_x < 0)
	{
		g_info->step_x = -1;
		side_dist_x = (g_info->pos_x - map_x) * delta_dist_x;
	}
	else
	{
		g_info->step_x = 1;
		side_dist_x = (map_x + 1.0 - g_info->pos_x) * delta_dist_x;
	}
	return (side_dist_x);
}

void		calc_hit(int *hit)
{
	while (*hit == 0)
	{
		if (g_info->side_dist_x < g_info->side_dist_y)
		{
			g_info->side_dist_x += g_info->delta_dist_x;
			g_info->map_x += g_info->step_x;
			g_map->side = 0;
		}
		else
		{
			g_info->side_dist_y += g_info->delta_dist_y;
			g_info->map_y += g_info->step_y;
			g_map->side = 1;
		}
		if (g_map->map[g_info->map_x][g_info->map_y] == '1')
			*hit = 1;
	}
}

void		move_ray(void)
{
	if (g_map->side == 0)
		g_info->ray_len = (g_info->map_x - g_info->pos_x
				+ (1 - g_info->step_x) / 2) / g_info->ray_dir_x;
	else
		g_info->ray_len = (g_info->map_y - g_info->pos_y
				+ (1 - g_info->step_y) / 2) / g_info->ray_dir_y;
}
