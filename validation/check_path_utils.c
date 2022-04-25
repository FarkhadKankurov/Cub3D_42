#include "../includes/cub.h"
#include "../includes/map_struct.h"

void	pass_print_chars(char **str, int *length)
{
	while (ft_isprint(**str))
	{
		(*str)++;
		(*length)++;
	}
}

void	pass_ptr(char **str, int num_chars, char *flag, char flag_init)
{
	*str += num_chars;
	*flag = flag_init;
}

int		pass_arg_no_so_we(char **str, char *flag)
{
	if (ft_strncmp(*str, "NO", 2) == 0)
		pass_ptr(str, 2, flag, 'N');
	else if (ft_strncmp(*str, "SO", 2) == 0)
		pass_ptr(str, 2, flag, 'S');
	else if (ft_strncmp(*str, "WE", 2) == 0)
		pass_ptr(str, 2, flag, 'W');
	else if (ft_strncmp(*str, "EA", 2) == 0)
		pass_ptr(str, 2, flag, 'E');
	else if (ft_strncmp(*str, "S", 1) == 0)
		pass_ptr(str, 1, flag, 'P');
	else
		return (-1);
	return (1);
}
