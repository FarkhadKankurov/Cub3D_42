#include "includes/cub.h"
#include "includes/map_struct.h"

int	main(int argc, char **argv)
{
	start(argc, argv);
	init_mlx_core();
	init_textures();
	init_hero_position();
	ray_cast();
	if (g_flag->save == 1)
		screenshot();
	mlx_put_image_to_window(g_info->mlx, g_info->win, g_info->img, 0, 0);
	mlx_hook(g_info->win, 2, 1L << 0, &key_press, &g_info);
	mlx_hook(g_info->win, 17, 1L << 0, &close_app, &g_info);
	mlx_loop(g_info->mlx);
}
