#include "../../includes/cub.h"

int	check_flags_before_map(void)
{
	return (g_flag->resolution != 1 ||
			g_flag->floor_color != 1 || g_flag->ceil_color != 1 ||
			g_flag->path_east != 1 || g_flag->path_west != 1 ||
			g_flag->path_south != 1 || g_flag->path_north != 1 ||
			g_flag->path_sprite != 1);
}
