#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	len_needle;

	if (!*needle)
		return ((char*)haystack);
	len_needle = ft_strlen(needle);
	if (!ft_strlen(haystack) || len < len_needle)
		return (0);
	len -= --len_needle;
	while (len-- && *haystack)
	{
		a = (char*)haystack;
		b = (char*)needle;
		while (*b && *a == *b)
		{
			++a;
			++b;
		}
		if (*b == 0)
			return ((char*)haystack);
		++haystack;
	}
	return (0);
}
