#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	size_t		length;

	if (!s1 || !s2)
		return (NULL);
	length = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * length)))
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
