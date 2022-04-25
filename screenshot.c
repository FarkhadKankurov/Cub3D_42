#include "includes/map_struct.h"
#include "includes/cub.h"

static void		fill_img(int fd)
{
	int i;
	int j;
	int color;

	i = g_map->resolution_y;
	while (--i >= 0)
	{
		j = -1;
		while (++j < g_map->resolution_x)
		{
			color = *(int*)(g_info->addr + (i * g_info->line_length
					+ j * (g_info->bits_per_pixel / 8)));
			write(fd, &color, 4);
		}
	}
	close_app();
}

static	void	fill_header(int *fd)
{
	int		zero;
	int		pos_pixel_data;
	short	plane;
	int		size_screen;

	size_screen = g_map->resolution_x * g_map->resolution_y;
	plane = 1;
	pos_pixel_data = 54;
	zero = 0;
	write(*fd, "BM", 2);
	write(*fd, &size_screen, 4);
	write(*fd, &zero, 4);
	write(*fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(*fd, &pos_pixel_data, 4);
	write(*fd, &g_map->resolution_x, 4);
	write(*fd, &g_map->resolution_y, 4);
	write(*fd, &plane, 2);
}

void			screenshot(void)
{
	int		fd;
	int		size_screen;
	int		zero;
	short	plane;
	int		size;

	free(g_flag);
	plane = 1;
	zero = 0;
	size_screen = g_map->resolution_x * g_map->resolution_y;
	size = size_screen;
	fd = open("./screenshot.bmp", O_CREAT | O_RDWR, 0666);
	if (fd < 0)
		exit(1);
	fill_header(&fd);
	plane = 32;
	write(fd, &plane, 2);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	fill_img(fd);
}
