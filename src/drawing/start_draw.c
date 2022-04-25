#include "../../includes/map_struct.h"
#include "../../includes/cub.h"

void		init_struct_params_raycast(int side,
		int line_height, int draw_start)
{
	if (side == 0 && g_info->ray_dir_x > 0)
		g_info->tex_x = g_text_north->width - g_info->tex_x - 1;
	if (side == 1 && g_info->ray_dir_y < 0)
		g_info->tex_x = g_text_north->width - g_info->tex_x - 1;
	g_info->step = 1.0 * g_text_north->height / line_height;
	g_info->tex_pos = (draw_start - g_map->resolution_y / 2 + line_height
			/ 2) * g_info->step;
}

void		draw_textures(int x, int draw_start, int draw_end, int side)
{
	int y;

	y = draw_start;
	while (y < draw_end)
	{
		if (side == 0)
			draw_south_north(x, y);
		else if (g_info->step_y > 0)
			draw_east(x, y);
		else
			draw_west(x, y);
		y++;
	}
}

void		draw_main(int x, double ray_len, int side)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;

	line_height = (int)(g_map->resolution_y / ray_len);
	draw_start = -line_height / 2 + g_map->resolution_y / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + g_map->resolution_y / 2;
	if (draw_end >= g_map->resolution_y)
		draw_end = g_map->resolution_y - 1;
	if (side == 0)
		wall_x = g_info->pos_y + ray_len * g_info->ray_dir_y;
	else
		wall_x = g_info->pos_x + ray_len * g_info->ray_dir_x;
	wall_x -= floor((wall_x));
	g_info->tex_x = (int)(wall_x * (double)(g_text_north->width));
	init_struct_params_raycast(side, line_height, draw_start);
	draw_cell(draw_start, x);
	draw_textures(x, draw_start, draw_end, side);
	draw_floor(draw_end, x);
}
