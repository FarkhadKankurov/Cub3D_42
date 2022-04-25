#include "../includes/map_struct.h"

void	pass_digits(char **str, int *length)
{
	while (ft_isdigit(**str))
	{
		(*length)++;
		(*str)++;
	}
}

int		create_number(char **str, char flag)
{
	char	*str_temp;
	char	*temp;
	int		length;
	int		ret;

	length = 0;
	pass_spaces(str);
	if (!ft_isdigit(**str))
		return (-1);
	temp = *str;
	pass_digits(str, &length);
	length++;
	if (!(str_temp = ft_substr(temp, 0, length)))
		return (-1);
	ret = ft_atoi(str_temp);
	if (flag == 'x')
		g_map->resolution_x = ret;
	else
		g_map->resolution_y = ret;
	free(str_temp);
	return (1);
}

int		check_resolution(char *str, char **str2)
{
	pass_spaces(&str);
	if (*str == 'R' && g_flag->resolution == 1)
	{
		g_flag->resolution = -1;
		return (-1);
	}
	if (*str == 'R')
		str++;
	else
		return (-1);
	create_number(&str, 'x');
	create_number(&str, 'y');
	pass_spaces(&str);
	if (*str != '\0')
		return (-1);
	if (g_map->resolution_x <= 0 || g_map->resolution_y <= 0)
		return (-1);
	g_flag->resolution = 1;
	free(*str2);
	return (1);
}
