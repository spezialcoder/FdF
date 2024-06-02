NAME = fdf
CC = cc
LIBFT = $(PWD)/libft
MINILIBX = $(PWD)/MLX42
CFLAGS = -g $(MINILIBX)/libmlx42.a -lglfw -lm -lft -L$(LIBFT) -L$(MINILIBX) -framework Cocoa -framework OpenGL -framework IOKit #-Wall -Werror -Wextra

SRCS = fdf.c mlx_utilities.c matrix/matrix.c loader.c fdf_engine/fdf_engine.c \
	   fdf_engine/shaper.c fdf_engine/fdf_engine_utils.c fdf_engine/fdf_engine_hook.c \
	   fdf_engine/fdf_engine_heatmap.c

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MINILIBX)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re