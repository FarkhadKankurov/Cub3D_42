#include "../../includes/cub.h"

void	draw_east(int x, int y)
{
	int color;
	int tex_y;

	tex_y = (int)g_info->tex_pos & (g_text_east->height - 1);
	g_info->tex_pos += g_info->step;
	color = g_text_east->color[g_text_east->height * tex_y + g_info->tex_x];
	my_mlx_pixel_put(g_info, x, y, color);
}

void	draw_west(int x, int y)
{
	int tex_y;
	int color;

	tex_y = (int)g_info->tex_pos & (g_text_west->height - 1);
	g_info->tex_pos += g_info->step;
	color = g_text_west->color[g_text_west->height * tex_y + g_info->tex_x];
	my_mlx_pixel_put(g_info, x, y, color);
}

void	draw_south_north(int x, int y)
{
	int tex_y;
	int color;

	if (g_info->step_x > 0)
	{
		tex_y = (int)g_info->tex_pos & (g_text_south->height - 1);
		g_info->tex_pos += g_info->step;
		color = g_text_south->color[g_text_south->height * tex_y
			+ g_info->tex_x];
		my_mlx_pixel_put(g_info, x, y, color);
	}
	else
	{
		tex_y = (int)g_info->tex_pos & (g_text_north->height - 1);
		g_info->tex_pos += g_info->step;
		color = g_text_north->color[g_text_north->height
			* tex_y + g_info->tex_x];
		my_mlx_pixel_put(g_info, x, y, color);
	}
}

void	draw_floor(int draw_end, int x)
{
	int y;

	y = draw_end;
	while (y < g_map->resolution_y)
	{
		my_mlx_pixel_put(g_info, x, y, g_map->floor_color);
		y++;
	}
}

void	draw_cell(int draw_start, int x)
{
	int y;

	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(g_info, x, y, g_map->cell_color);
		y++;
	}
}
