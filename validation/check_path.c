#include "../includes/map_struct.h"
#include "../includes/map_struct.h"

void			fill_struct(char flag, char *str_temp)
{
	if (flag == 'N')
	{
		g_map->path_north = str_temp;
		g_flag->path_north = 1;
	}
	else if (flag == 'S')
	{
		g_map->path_south = str_temp;
		g_flag->path_south = 1;
	}
	else if (flag == 'W')
	{
		g_map->path_west = str_temp;
		g_flag->path_west = 1;
	}
	else if (flag == 'E')
	{
		g_map->path_east = str_temp;
		g_flag->path_east = 1;
	}
	else
	{
		g_map->path_sprite = str_temp;
		g_flag->path_sprite = 1;
	}
}

static int		check_flags_north(char flag)
{
	if (flag == 'N' && g_flag->path_north == 1)
	{
		g_flag->path_north = -1;
		return (-1);
	}
	return (1);
}

static int		check_flags(char flag)
{
	if (check_flags_north(flag) == -1)
		return (-1);
	if (flag == 'S' && g_flag->path_south == 1)
	{
		g_flag->path_south = -1;
		return (-1);
	}
	if (flag == 'W' && g_flag->path_west == 1)
	{
		g_flag->path_west = -1;
		return (-1);
	}
	if (flag == 'E' && g_flag->path_east == 1)
	{
		g_flag->path_east = -1;
		return (-1);
	}
	if (flag == 'P' && g_flag->path_sprite == 1)
	{
		g_flag->path_sprite = -1;
		return (-1);
	}
	return (1);
}

int				check_path(char *str, char **str2)
{
	char	*ptr;
	int		length;
	char	*str_temp;
	char	flag;

	length = 0;
	pass_spaces(&str);
	if (!(*str))
		return (-1);
	if (pass_arg_no_so_we(&str, &flag) == -1)
		return (-1);
	if (check_flags(flag) == -1)
		return (1);
	pass_spaces(&str);
	if (!(*str))
		return (-1);
	ptr = str;
	pass_print_chars(&str, &length);
	if (str[ft_strlen(str)] == ' ')
		return (-1);
	if (!(str_temp = ft_substr(ptr, 0, length)))
		return (-1);
	fill_struct(flag, str_temp);
	free(*str2);
	return (1);
}
