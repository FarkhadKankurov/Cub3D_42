NAME = cub3D
SRCS =	screenshot.c main.c src/drawing/calc_params.c src/drawing/drawing.c \
		src/drawing/ray_cast.c src/drawing/start_draw.c src/error_handling/close_app.c \
		src/error_handling/error_texture.c src/moving/key_move.c src/moving/key_rotate.c \
		src/sprites/draw_sprites.c src/sprites/sort_sprites.c src/utils/utils.c \
		src/init_hero_position.c src/init_mlx_core.c src/init_textures.c \
		validation/check_colors.c validation/check_path.c validation/check_resolution.c \
		validation/find_sprites.c validation/start_check.c validation/validate_arg.c \
		validation/error_handling/close_validation.c validation/utils/check_flags.c \
		validation/utils/check_symbols.c validation/utils/ft_atoi_nospace.c \
		validation/utils/gnl_loop_params.c validation/utils/init_map.c validation/utils/ft_nbr_len.c\
		validation/utils/memory_free.c validation/check_path_utils.c
MLX = -L. -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
MLX				= mlx/libmlx.dylib
LIBFT           = libft.a

OBJSRCS = $(SRCS:.c=.o)

$(NAME) : $(SRCS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./mlx
	@rm -f screenshot.bmp
	@rm -f cub3D
	@gcc -Wall -Wextra -Werror $(SRCS) $(MLX) ./libft/libft.a -o $(NAME)
	@mv mlx/libmlx.dylib libmlx.dylib
	@echo "\033[33m[Done !]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx

fclean : clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -rf $(NAME)
	rm -f libmlx.dylib
	rm -f screenshot.bmp

re : fclean all

bonus : $(NAME)

.PHONY:	all clean fclean re
