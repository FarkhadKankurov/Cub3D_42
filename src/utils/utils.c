/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:04:37 by drarlean          #+#    #+#             */
/*   Updated: 2021/02/14 11:06:39 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void				my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int		get_pixel(int x, int y)
{
	char	*dst;

	dst = g_texture->addr + (y * g_texture->line_length + x *
			(g_texture->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void				change_pic(void)
{
	g_info->img = mlx_new_image(g_info->mlx, g_map->resolution_x,
			g_map->resolution_y);
	g_info->addr = mlx_get_data_addr(g_info->img, &g_info->bits_per_pixel,
			&g_info->line_length, &g_info->endian);
	ray_cast();
	mlx_put_image_to_window(g_info->mlx, g_info->win, g_info->img, 0, 0);
	mlx_do_sync(g_info->mlx);
}
