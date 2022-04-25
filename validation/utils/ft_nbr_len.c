#include "../../includes/map_struct.h"

int		ft_nbr_len(unsigned long long num)
{
	int length;

	if (num == 0)
		return (1);
	length = 0;
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

void	pass_spaces(char **str)
{
	while (is_space(**str))
		(*str)++;
}

int		check_digit(char *str, int nbr_len)
{
	while (nbr_len--)
	{
		if (!ft_isdigit(*str))
			return (-1);
		str++;
	}
	return (1);
}
