#include "../../includes/cub.h"

static int		check_null_term(char c, char **str2)
{
	if (c == '\0')
	{
		free(*str2);
		return (1);
	}
	return (-1);
}

static int		check_null_term_with_flag(char c, char **str2)
{
	if (c == '\0' && g_flag->is_done2 != 1)
	{
		free(*str2);
		return (1);
	}
	return (-1);
}

static void		check(char **str, int file)
{
	if (check_flags_before_map())
		check_game_params(*str, file);
	g_flag->is_done = 1;
}

t_list			*loop(int file, char **str)
{
	t_list *head;

	head = NULL;
	while (get_next_line(file, str))
	{
		if (g_flag->is_done != 1)
		{
			if (check_resolution(*str, str) == 1)
				continue;
			else if (check_path(*str, str) == 1)
				continue;
			else if (check_colors(*str, str) == 1)
				continue;
			else if (check_null_term(**str, str) == 1)
				continue;
			check(str, file);
		}
		if (check_null_term_with_flag(**str, str) == 1)
			continue;
		else
			g_flag->is_done2 = 1;
		ft_lstadd_back(&head, ft_lstnew(*str));
	}
	return (head);
}
