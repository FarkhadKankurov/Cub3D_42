#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	while ((*s1 || *s2) && n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
		{
			if (*(unsigned char*)s1 - *(unsigned char*)s2 < 0)
				return (-1);
			if (*(unsigned char*)s1 - *(unsigned char*)s2 > 0)
				return (1);
			return (0);
		}
	}
	return (0);
}
