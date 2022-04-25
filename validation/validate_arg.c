#include "../includes/map_struct.h"
#include "../includes/cub.h"

void			close_validation(void)
{
	free(g_map);
	free(g_hero);
	free(g_sprite);
	free(g_flag);
	exit(0);
}

void			check_save(char **argv)
{
	if (*argv[2] && ft_strncmp(argv[2], "--save", 6) == 0)
		g_flag->save = 1;
	else
	{
		write(1, "Error\nIncorrect arguments", 26);
		close_validation();
	}
}

static void		validate_extention(char *ptr)
{
	if (ft_strncmp(ptr, "cub", 3) != 0)
	{
		write(1, "Error\nIncorrect map extention", 29);
		close_validation();
	}
}

int				validate_argc(int argc, char **argv)
{
	char *ptr;

	ptr = NULL;
	if (argc > 1 && argc < 4)
	{
		if (argc < 4)
		{
			if (!(ptr = ft_strrchr(argv[1], '.')))
			{
				write(1, "Error\nIncorrect map name", 25);
				close_validation();
			}
			ptr++;
		}
		if (argc == 3)
			check_save(argv);
	}
	else
	{
		write(1, "Error\nIncorrect arguments", 26);
		close_validation();
	}
	validate_extention(ptr);
	return (1);
}
