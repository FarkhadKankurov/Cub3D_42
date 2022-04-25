#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char*)arr1) != (*(unsigned char*)arr2))
			return (*(unsigned char*)arr1 - *(unsigned char*)arr2);
		arr1++;
		arr2++;
	}
	return (0);
}
