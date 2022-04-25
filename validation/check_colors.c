#include "../includes/map_struct.h"
#include "../includes/libft.h"

void			init_flags(char flag, int color)
{
	if (flag == 'F')
	{
		g_map->floor_color = color;
		g_flag->floor_color = 1;
	}
	if (flag == 'C')
	{
		g_map->cell_color = color;
		g_flag->ceil_color = 1;
	}
}

int				pass_symbols(char **str, char *flag)
{
	if (!*str)
		return (-1);
	if (**str == 'F')
	{
		*flag = 'F';
		(*str)++;
	}
	else if (**str == 'C')
	{
		*flag = 'C';
		(*str)++;
	}
	else
		return (-1);
	return (1);
}

static int		close_fun(char flag)
{
	if (flag == 'F' && g_flag->floor_color == 1)
	{
		g_flag->floor_color = -1;
		return (-1);
	}
	if (flag == 'C' && g_flag->ceil_color == 1)
	{
		g_flag->ceil_color = -1;
		return (-1);
	}
	return (1);
}

int				init_colors(int *r, int *g, int *b, char **str)
{
	*r = ft_atoi_nospace(*str);
	if (check_digit(*str, ft_nbr_len(*r)) == -1)
		return (-1);
	*str += ft_nbr_len(*r);
	if (**str == ',')
		(*str)++;
	else
		return (-1);
	*g = ft_atoi_nospace(*str);
	if (check_digit(*str, ft_nbr_len(*g)) == -1)
		return (-1);
	*str += ft_nbr_len(*g);
	if (**str == ',')
		(*str)++;
	else
		return (-1);
	*b = ft_atoi_nospace(*str);
	if (check_digit(*str, ft_nbr_len(*b)) == -1)
		return (-1);
	*str += ft_nbr_len(*b);
	if ((*r < 0 || *r > 255) ||
		(*g < 0 || *g > 255) ||
		(*b < 0 || *b > 255))
		return (-1);
	return (1);
}

int				check_colors(char *str, char **str2)
{
	int		r;
	int		g;
	int		b;
	int		color;
	char	flag;

	pass_spaces(&str);
	if (!*str)
		return (-1);
	if (pass_symbols(&str, &flag) == -1)
		return (-1);
	if (close_fun(flag) == -1)
		return (-1);
	pass_spaces(&str);
	if (!*str)
		return (-1);
	if ((init_colors(&r, &g, &b, &str) == -1))
		return (-1);
	color = r << 16 | g << 8 | b;
	init_flags(flag, color);
	if (*str != '\0')
		return (-1);
	free(*str2);
	return (1);
}
