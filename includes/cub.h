#ifndef CUB_H
# define CUB_H
# include "map_struct.h"
# include "libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			tex_x;
	double		step;
	double		tex_pos;
	double		ray_len;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	double		move_speed;
	double		rot_speed;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			screen_x;
	int			screen_y;
}				t_info;

typedef struct	s_text {
	void		*ptr;
	int			tmp;
	int			width;
	int			height;
	int			*color;

}				t_text;

typedef struct	s_texture
{
	int			width;
	int			height;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

t_info			*g_info;
t_text			*g_text_south;
t_text			*g_text_north;
t_text			*g_text_west;
t_text			*g_text_east;
t_texture		*g_texture;

void			my_mlx_pixel_put(t_info *data, int x, int y, int color);
void			change_pic();
void			texture_error();
unsigned int	get_pixel(int x, int y);
void			draw_sprites(double *buffer);
int				close_app();
void			init_mlx_core();
void			ray_cast();
void			sort_sprites(double *sprite_distance);
int				key_press(int key);
void			rotate_right();
void			rotate_left();
int				close_mlx_init();
void			screenshot();
void			init_textures();
void			init_hero_position();
void			draw_main(int x, double ray_len, int side);
void			draw_east(int x, int y);
void			draw_west(int x, int y);
void			draw_south_north(int x, int y);
void			draw_floor(int draw_end, int x);
void			draw_cell(int draw_start, int x);
double			calc_side_dist_x(int map_x, double delta_dist_x);
double			calc_side_dist_y(int map_y, double delta_dist_y);
void			calc_hit(int *hit);
void			move_ray();
void			init_struct_params(double camera_x);
void			init_struct_params_raycast(int side,
		int line_height, int draw_start);
#endif
