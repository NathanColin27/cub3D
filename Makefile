NAME =	cub3D

FLAGS = -Wall -Wextra -O2 -g

GCC = clang $(FLAGS)

SRC_PATH =	srcs/
SRC_NAME = 	main.c \
			parser.c \
			error_handling.c \
			init.c \
			init2.c \
			parse_map_data.c \
			map_parser.c \
			map_checker.c \
			display.c \
			keys.c \
			utils.c \
			raycaster.c \
			raycaster2.c \
			free.c \
			bmp.c \
			sprites.c


SRCS =	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS =	$(SRCS:.c=.o)

INCLUDES =	includes/cub3d.h

OSNAME = $(shell uname)

ifeq ($(OSNAME),Darwin)
	MLX_PATH = 
	MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
	MLX = 
else
	MLX = libmlx.a
	MLX_PATH = ./minilibx-linux/
	MLX_FLAGS = -lm -lX11 -lXext
endif

LIBFT_PATH = ./libft/

LIBFT = libft.a

all: $(NAME) 

%.o: %.c
	$(GCC) -c -o $@ $<

re_libs:
	@$(MAKE) -C libft re
	@$(MAKE) -C libft clean
	@$(MAKE) -C minilibx-linux re
	@$(MAKE) -C minilibx-linux clean

$(NAME): re_libs
	@rm -rf cube.bmp
	$(GCC) $(SRCS) $(LIBFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all