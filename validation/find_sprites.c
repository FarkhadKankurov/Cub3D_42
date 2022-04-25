#include "../includes/map_struct.h"

void	find_num_of_sprites(void)
{
	int num;
	int i;
	int j;

	i = 0;
	num = 0;
	while (i < g_map->num_of_strings)
	{
		j = 0;
		while (j < (int)ft_strlen(g_map->map[i]))
		{
			if (g_map->map[i][j] == '2')
				num++;
			j++;
		}
		i++;
	}
	g_map->num_of_sprites = num;
	init_sprite_coord();
}

void	init_x_y(float *x, float *y)
{
	g_sprite->x = x;
	g_sprite->y = y;
}

void	init_sprite_coord(void)
{
	float	*x;
	float	*y;
	int		i;
	int		j;
	int		count;

	x = malloc(sizeof(float) * g_map->num_of_sprites);
	y = malloc(sizeof(float) * g_map->num_of_sprites);
	i = -1;
	count = 0;
	while (++i < g_map->num_of_strings)
	{
		j = -1;
		while (++j < (int)ft_strlen(g_map->map[i]))
		{
			if (g_map->map[i][j] == '2')
			{
				x[count] = i + 0.5;
				y[count] = j + 0.5;
				g_map->map[i][j] = '0';
				count++;
			}
		}
	}
	init_x_y(x, y);
}
