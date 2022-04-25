#include "../../includes/cub.h"

int				ft_atoi_nospace(char *str)
{
	int						is_negative;
	unsigned long long int	result;

	result = 0;
	is_negative = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (ft_isdigit(*str + '\0'))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (result > 9223372036854775807)
		return (is_negative == 1 ? -1 : 0);
	return ((int)(result * is_negative));
}
