#include "../../includes/cub.h"

static void		put_color(int i, int j, int tex_x)
{
	int				d;
	int				tex_y;
	unsigned int	color;

	d = (j) * 256 - g_map->resolution_y * 128 +
			g_sprite->sprite_height * 128;
	tex_y = ((d * g_texture->height) / g_sprite->sprite_height) / 256;
	color = get_pixel(tex_x, tex_y);
	if (color > 127)
		my_mlx_pixel_put(g_info, i, j, (int)color);
}

static void		drawing(double *buffer)
{
	int i;
	int j;
	int tex_x;

	i = g_sprite->draw_start_x;
	while (i < g_sprite->draw_end_x)
	{
		tex_x = (int)(256 * (i - (-g_sprite->sprite_width / 2 +
						g_sprite->sprite_screen_x)) * g_texture->width
				/ g_sprite->sprite_width) / 256;
		j = g_sprite->draw_start_y;
		if (g_sprite->transform_y > 0 && i > 0 && i < g_map->resolution_x &&
			g_sprite->transform_y < buffer[i])
			while (j < g_sprite->draw_end_y)
			{
				put_color(i, j, tex_x);
				j++;
			}
		i++;
	}
}

static void		init_sprites(int i)
{
	double sprite_x;
	double sprite_y;
	double inv_det;

	sprite_x = g_sprite->x[i] - g_info->pos_x;
	sprite_y = g_sprite->y[i] - g_info->pos_y;
	inv_det = 1.0 / (g_info->plane_x * g_info->dir_y -
			g_info->dir_x * g_info->plane_y);
	g_sprite->transform_x = inv_det * (g_info->dir_y * sprite_x -
			g_info->dir_x * sprite_y);
	g_sprite->transform_y = inv_det * (-g_info->plane_y * sprite_x +
			g_info->plane_x * sprite_y);
	g_sprite->sprite_screen_x = (int)(((float)g_map->resolution_x / 2) *
			(1 + g_sprite->transform_x / g_sprite->transform_y));
	g_sprite->sprite_height = abs((int)(g_map->resolution_y /
				(g_sprite->transform_y)));
}

static void		costyl(void)
{
	if (g_sprite->draw_start_x < 0)
		g_sprite->draw_start_x = 0;
	g_sprite->draw_end_x = g_sprite->sprite_width / 2 +
		g_sprite->sprite_screen_x;
	if (g_sprite->draw_end_x >= g_map->resolution_x)
		g_sprite->draw_end_x = g_map->resolution_x - 1;
}

void			draw_sprites(double *buffer)
{
	int i;

	i = 0;
	while (i < g_map->num_of_sprites)
	{
		init_sprites(i);
		g_sprite->draw_start_y = -g_sprite->sprite_height / 2 +
			g_map->resolution_y / 2;
		if (g_sprite->draw_start_y < 0)
			g_sprite->draw_start_y = 0;
		g_sprite->draw_end_y = g_sprite->sprite_height / 2 +
			g_map->resolution_y / 2;
		if (g_sprite->draw_end_y >= g_map->resolution_y)
			g_sprite->draw_end_y = g_map->resolution_y - 1;
		g_sprite->sprite_width = abs((int)(g_map->resolution_y /
					(g_sprite->transform_y)));
		g_sprite->draw_start_x = -g_sprite->sprite_width / 2 +
			g_sprite->sprite_screen_x;
		costyl();
		drawing(buffer);
		i++;
	}
}
