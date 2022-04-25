#include "libft.h"

static int		my_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int				ft_tolower(int c)
{
	if (my_isupper(c))
		return (c + 32);
	return (c);
}
