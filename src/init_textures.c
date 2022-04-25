#include "../includes/map_struct.h"
#include "../includes/cub.h"

static void		init_south_north(void)
{
	g_text_south = malloc(sizeof(t_text));
	g_text_north = malloc(sizeof(t_text));
	if (!(g_text_south->ptr = mlx_xpm_file_to_image(g_info->mlx,
					g_map->path_south, &g_text_south->width,
					&g_text_south->height)))
		texture_error();
	g_text_south->color = (int*)mlx_get_data_addr(g_text_south->ptr,
			&g_text_south->tmp, &g_text_south->tmp, &g_text_south->tmp);
	if (!(g_text_north->ptr = mlx_xpm_file_to_image(g_info->mlx,
					g_map->path_north,
					&g_text_north->width, &g_text_north->height)))
		texture_error();
	g_text_north->color = (int*)mlx_get_data_addr(g_text_north->ptr,
			&g_text_north->tmp, &g_text_north->tmp, &g_text_north->tmp);
}

static void		init_west_east(void)
{
	g_text_west = malloc(sizeof(t_text));
	g_text_east = malloc(sizeof(t_text));
	if (!(g_text_west->ptr = mlx_xpm_file_to_image(g_info->mlx,
					g_map->path_west, &g_text_west->width,
					&g_text_west->height)))
		texture_error();
	g_text_west->color = (int*)mlx_get_data_addr(g_text_west->ptr,
			&g_text_west->tmp, &g_text_west->tmp, &g_text_west->tmp);
	if (!(g_text_east->ptr = mlx_xpm_file_to_image(g_info->mlx,
					g_map->path_east, &g_text_east->width,
					&g_text_east->height)))
		texture_error();
	g_text_east->color = (int*)mlx_get_data_addr(g_text_east->ptr,
			&g_text_east->tmp, &g_text_east->tmp, &g_text_east->tmp);
}

static void		init_sprite(void)
{
	g_texture = malloc(sizeof(t_texture));
	if (!(g_texture->img = mlx_xpm_file_to_image(g_info->mlx,
					g_map->path_sprite, &g_texture->width,
					&g_texture->height)))
	{
		texture_error();
	}
	g_texture->addr = mlx_get_data_addr(g_texture->img,
			&g_texture->bits_per_pixel,
			&g_texture->line_length, &g_texture->endian);
}

void			init_textures(void)
{
	init_south_north();
	init_west_east();
	init_sprite();
}
