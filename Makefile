NAME = fdf
CC = cc
LIBFT = $(PWD)/lib/libft
LIBMLX= $(PWD)/lib/MLX42
CFLAGS = -g $(LIBMLX)/build/libmlx42.a -lglfw -lm -lft -L$(LIBFT) -L$(LIBMLX) \
	-framework Cocoa -framework OpenGL -framework IOKit  \
	 -Wunreachable-code -Ofast -I $(LIBMLX)/include -I $(LIBFT) \
	  -lglfw -pthread -Wextra -Wall -Werror

SRCS = fdf.c mlx_utilities.c matrix/matrix.c loader.c fdf_engine/fdf_engine.c \
	   fdf_engine/shaper.c fdf_engine/fdf_engine_utils.c fdf_engine/fdf_engine_hook.c \
	   fdf_engine/fdf_engine_heatmap.c fdf_engine/fdf_engine_space.c loader_utils.c \
	   fdf_engine/space_axis_colors.c

all: libmlx $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	$(MAKE) -C $(LIBMLX)/build -j4

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(LIBMLX)/build

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx