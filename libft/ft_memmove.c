#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	void *ret;

	if (!destination && !source)
		return (0);
	ret = destination;
	if (source < destination)
	{
		source += n;
		destination += n;
		while (n--)
		{
			*(char*)--destination = *(char*)--source;
		}
	}
	else
		while (n--)
			*(char*)destination++ = *(char*)source++;
	return (ret);
}
