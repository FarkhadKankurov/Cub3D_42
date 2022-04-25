#include "libft.h"
#include "get_next_line.h"

char		*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

void		ft_strclr(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

char		*remind(char *reminder, char **line)
{
	char *ptr;

	ptr = 0;
	if (reminder)
		if ((ptr = ft_strchr(reminder, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++ptr);
		}
		else
			*line = ft_strdup(reminder);
	else
		*line = ft_strdup("");
	return (ptr);
}

void		costyl(char **pointer, char **reminder, char *buf)
{
	if ((*pointer = ft_strchr(buf, '\n')))
	{
		**pointer = '\0';
		*pointer += 1;
		ft_strclr(reminder);
		*reminder = ft_strdup(*pointer);
	}
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte_was_read;
	static char		*reminder;
	char			*pointer;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
			|| read(fd, buf, 0) < 0)
		return (-1);
	pointer = remind(reminder, line);
	while (!pointer && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		costyl(&pointer, &reminder, buf);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strclr(&tmp);
	}
	ft_strclr(&buf);
	if (!pointer)
		ft_strclr(&reminder);
	return (pointer ? 1 : 0);
}
