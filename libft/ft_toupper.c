#include "libft.h"

static int		my_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int				ft_toupper(int c)
{
	if (my_islower(c))
		return (c + ('A' - 'a'));
	return (c);
}
