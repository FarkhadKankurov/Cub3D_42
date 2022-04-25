#include "../../includes/map_struct.h"
#include "../../includes/cub.h"

double			*sort_distance(double *sprite_distance)
{
	int i;

	i = 0;
	while (i < g_map->num_of_sprites)
	{
		sprite_distance[i] = ((g_info->pos_x - g_sprite->x[i]) *
				(g_info->pos_x - g_sprite->x[i]) + (g_info->pos_y -
					g_sprite->y[i]) * (g_info->pos_y - g_sprite->y[i]));
		i++;
	}
	return (sprite_distance);
}

static void		swap_variables(int j, float temp2, float temp3)
{
	g_sprite->x[j] = g_sprite->x[j + 1];
	g_sprite->x[j + 1] = temp2;
	g_sprite->y[j] = g_sprite->y[j + 1];
	g_sprite->y[j + 1] = temp3;
}

void			sort_sprites(double *sprite_distance)
{
	int		i;
	int		j;
	double	temp;
	float	temp2;
	float	temp3;

	sprite_distance = sort_distance(sprite_distance);
	i = 0;
	while (i < g_map->num_of_sprites)
	{
		j = -1;
		while (++j < g_map->num_of_sprites - 1)
		{
			if (sprite_distance[j] < sprite_distance[j + 1])
			{
				temp = sprite_distance[j];
				temp2 = g_sprite->x[j];
				temp3 = g_sprite->y[j];
				sprite_distance[j] = sprite_distance[j + 1];
				sprite_distance[j + 1] = temp;
				swap_variables(j, temp2, temp3);
			}
		}
		i++;
	}
}
