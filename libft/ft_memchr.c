#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	void *point;

	point = (void*)arr;
	while (n--)
	{
		if (*(char*)point == (char)c)
			return (point);
		++point;
	}
	return (0);
}
