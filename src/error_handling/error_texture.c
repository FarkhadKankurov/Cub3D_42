#include "../../includes/map_struct.h"
#include "../../includes/cub.h"

void	texture_error(void)
{
	write(1, "Texture error", 13);
	free(g_info);
	free(g_text_south);
	free(g_text_north);
	free(g_text_west);
	free(g_text_east);
	free(g_texture);
	exit(0);
}
