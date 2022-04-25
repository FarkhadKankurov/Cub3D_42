#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = (int)ft_strlen(str) + 1;
	while (i--)
	{
		if (*(str + i) == (char)ch)
			return ((char*)str + i);
	}
	return (0);
}
