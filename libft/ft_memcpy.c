#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	void *ptr;

	ptr = destination;
	if (!destination && !source)
		return (0);
	while (n--)
		*(char*)destination++ = *(char*)source++;
	return (ptr);
}
