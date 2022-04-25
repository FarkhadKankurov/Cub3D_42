#ifndef MAP_STRUCT_H
# define MAP_STRUCT_H
# include <fcntl.h>
# include "libft.h"

typedef struct		s_map
{
	int				resolution_x;
	int				resolution_y;
	char			*path_north;
	char			*path_south;
	char			*path_west;
	char			*path_east;
	char			*path_sprite;
	int				floor_color;
	int				cell_color;
	char			**map;
	int				num_of_strings;
	int				num_of_sprites;
	size_t			column;
	int				side;
}					t_map;

typedef struct		s_sprite
{
	float			*x;
	float			*y;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
}					t_sprite;

typedef struct		s_flag
{
	int				resolution;
	int				path_north;
	int				path_south;
	int				path_west;
	int				path_east;
	int				path_sprite;
	int				floor_color;
	int				ceil_color;
	int				is_done;
	int				is_done2;
	int				save;
}					t_flag;

typedef struct		s_hero
{
	int				pos_x;
	int				pos_y;
	int				flag;
	char			direction;
}					t_hero;

int					check_resolution(char *str, char **str2);
void				find_num_of_sprites();
int					is_space(int c);
int					check_colors(char *str, char **str2);
int					ft_atoi_nospace(char *str);
void				list_clear(t_list *list);
void				content_clear(t_list *list);
void				free_two_dim_array(char **arr, int size);
int					validate_argc(int argc, char **argv);
int					start(int argc, char **argv);
void				init_sprite_coord();
void				check_open(char *err_msg);
int					check_flags_before_map();
void				check_game_params(char *str, int file);
void				close_all_with_list(int file, char **str, t_list *head);
t_list				*loop(int file, char **str);
int					validate_map_chars(int i, int j);
void				calloc_error(t_list *head);
void				close_find_player(char *err_msg);
void				init_hero_pos(int i, int j);
int					check_symbol(char c);
int					check_empty_symbol(char c);
void				check_open_spaces(int i, int j);
int					ft_nbr_len(unsigned long long num);
void				pass_spaces(char **str);
int					check_digit(char *str, int nbr_len);
void				pass_print_chars(char **str, int *length);
void				pass_ptr(char **str, int num_chars, char *flag,
		char flag_init);
int					pass_arg_no_so_we(char **str, char *flag);
char				**make_map(t_list *head, int size);
int					make_copy();
void				check_zeros();
void				flood_fill(char **map, int x, int y);
int					check_path(char *str, char **str2);
t_map				*g_map;
t_flag				*g_flag;
t_hero				*g_hero;
t_sprite			*g_sprite;
#endif
