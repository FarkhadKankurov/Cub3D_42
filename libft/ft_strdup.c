#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		length;
	int		i;

	length = (int)ft_strlen(str);
	if (!(ptr = (char*)malloc(sizeof(char) * (length) + 1)))
		return (NULL);
	ptr[length] = '\0';
	i = 0;
	while (length--)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
