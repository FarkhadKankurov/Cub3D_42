#include "../../includes/cub.h"
#include "../../includes/map_struct.h"

void	move_forward(void)
{
	mlx_destroy_image(g_info->mlx, g_info->img);
	if (g_map->map[(int)(g_info->pos_x + g_info->dir_x * g_info->move_speed)]
			[(int)(g_info->pos_y)] == '0')
		g_info->pos_x += g_info->dir_x * g_info->move_speed;
	if (g_map->map[(int)(g_info->pos_x)][(int)(g_info->pos_y + g_info->dir_y
				* g_info->move_speed)] == '0')
		g_info->pos_y += g_info->dir_y * g_info->move_speed;
	change_pic();
}

void	move_backward(void)
{
	mlx_destroy_image(g_info->mlx, g_info->img);
	if (g_map->map[(int)(g_info->pos_x - g_info->dir_x * g_info->move_speed)]
			[(int)(g_info->pos_y)] == '0')
		g_info->pos_x -= g_info->dir_x * g_info->move_speed;
	if (g_map->map[(int)(g_info->pos_x)][(int)(g_info->pos_y - g_info->dir_y
				* g_info->move_speed)] == '0')
		g_info->pos_y -= g_info->dir_y * g_info->move_speed;
	change_pic();
}

void	move_left(void)
{
	mlx_destroy_image(g_info->mlx, g_info->img);
	if (g_map->map[(int)(g_info->pos_x - g_info->dir_y * g_info->move_speed)]
			[(int)(g_info->pos_y)] == '0')
		g_info->pos_x -= g_info->dir_y * g_info->move_speed;
	if (g_map->map[(int)(g_info->pos_x)][(int)(g_info->pos_y + g_info->dir_x
				* g_info->move_speed)] == '0')
		g_info->pos_y += g_info->dir_x * g_info->move_speed;
	change_pic();
}

void	move_right(void)
{
	mlx_destroy_image(g_info->mlx, g_info->img);
	if (g_map->map[(int)(g_info->pos_x + g_info->dir_y * g_info->move_speed)]
			[(int)(g_info->pos_y)] == '0')
		g_info->pos_x += g_info->dir_y * g_info->move_speed;
	if (g_map->map[(int)(g_info->pos_x)][(int)(g_info->pos_y - g_info->dir_x
				* g_info->move_speed)] == '0')
		g_info->pos_y -= g_info->dir_x * g_info->move_speed;
	change_pic();
}

int		key_press(int key)
{
	if (key == 53)
		close_app();
	else if (key == 13)
		move_forward();
	else if (key == 1)
		move_backward();
	else if (key == 0)
		move_left();
	else if (key == 2)
		move_right();
	else if (key == 124)
		rotate_right();
	else if (key == 123)
		rotate_left();
	return (0);
}
