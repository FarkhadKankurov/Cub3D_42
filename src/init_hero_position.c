#include "../includes/map_struct.h"
#include "../includes/cub.h"

static void		init_hero_west_east(void)
{
	if (g_hero->direction == 'E')
	{
		g_info->dir_x = 0.001;
		g_info->dir_y = 1.001;
		g_info->plane_x = 0.66;
		g_info->plane_y = 0;
	}
	else if (g_hero->direction == 'W')
	{
		g_info->dir_x = 0.001;
		g_info->dir_y = -1.001;
		g_info->plane_x = -0.66;
		g_info->plane_y = 0;
	}
}

static void		init_hero_north_south(void)
{
	if (g_hero->direction == 'N')
	{
		g_info->dir_x = -1.01;
		g_info->dir_y = 0.01;
		g_info->plane_x = 0;
		g_info->plane_y = 0.66;
	}
	else if (g_hero->direction == 'S')
	{
		g_info->dir_x = 1.01;
		g_info->dir_y = 0.01;
		g_info->plane_x = 0;
		g_info->plane_y = -0.66;
	}
}

void			init_hero_position(void)
{
	g_info->pos_x = g_hero->pos_y + 0.5;
	g_info->pos_y = g_hero->pos_x + 0.5;
	g_info->move_speed = 0.1;
	g_info->rot_speed = 0.1;
	init_hero_north_south();
	init_hero_west_east();
}
