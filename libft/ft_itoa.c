#include "libft.h"

static int		length_count(int n)
{
	int length;

	length = 0;
	n = n < 0 ? -n : n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char		*ret_min_int(void)
{
	char *ret;

	ret = ft_strdup("-2147483648");
	return (ret);
}

static char		*ret_zero_value(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char		*calc_result(char *str, int temp, int length)
{
	while (temp > 0)
	{
		str[--length] = temp % 10 + '0';
		temp /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			temp;
	int			length;
	char		*str;

	if (n == -2147483648)
		return (ret_min_int());
	length = length_count(n);
	if (n < 0)
	{
		length++;
		temp = -n;
	}
	else
		temp = n;
	if (!(str = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (n == 0)
		return (ret_zero_value(str));
	if (n < 0)
		str[0] = '-';
	str[length] = 0;
	return (calc_result(str, temp, length));
}
