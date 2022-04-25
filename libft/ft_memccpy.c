#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	while (n--)
	{
		*(char*)destination++ = *(char*)source++;
		if (*(char*)(destination - 1) == (char)c)
			return (destination);
	}
	return (0);
}
