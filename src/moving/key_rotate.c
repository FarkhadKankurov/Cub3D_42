#include "../../includes/cub.h"
#include "../../includes/map_struct.h"

void	rotate_left(void)
{
	double	old_x;
	double	old_plane_x;

	mlx_destroy_image(g_info->mlx, g_info->img);
	old_x = g_info->dir_x;
	g_info->dir_x = g_info->dir_x * cos(g_info->rot_speed) - g_info->dir_y *
		sin(g_info->rot_speed);
	g_info->dir_y = old_x * sin(g_info->rot_speed) + g_info->dir_y *
		cos(g_info->rot_speed);
	old_plane_x = g_info->plane_x;
	g_info->plane_x = g_info->plane_x * cos(g_info->rot_speed) - g_info->plane_y
		* sin(g_info->rot_speed);
	g_info->plane_y = old_plane_x * sin(g_info->rot_speed) + g_info->plane_y
		* cos(g_info->rot_speed);
	change_pic();
}

void	rotate_right(void)
{
	double	old_x;
	double	old_plane_x;

	mlx_destroy_image(g_info->mlx, g_info->img);
	old_x = g_info->dir_x;
	g_info->dir_x = g_info->dir_x * cos(-g_info->rot_speed) - g_info->dir_y
		* sin(-g_info->rot_speed);
	g_info->dir_y = old_x * sin(-g_info->rot_speed) + g_info->dir_y
		* cos(-g_info->rot_speed);
	old_plane_x = g_info->plane_x;
	g_info->plane_x = g_info->plane_x * cos(-g_info->rot_speed)
		- g_info->plane_y * sin(-g_info->rot_speed);
	g_info->plane_y = old_plane_x * sin(-g_info->rot_speed)
		+ g_info->plane_y * cos(-g_info->rot_speed);
	change_pic();
}
