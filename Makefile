NAME =	cub3D

FLAGS = -Wall -Wextra -O2 -g

GCC = clang $(FLAGS)

SRCS = 	srcs/main.c \
		srcs/parser.c \
		srcs/error_handling.c \
		srcs/init.c \
		srcs/init2.c \
		srcs/parse_map_data.c \
		srcs/map_parser.c \
		srcs/map_checker.c \
		srcs/display.c \
		srcs/keys.c \
		srcs/utils.c \
		srcs/raycaster.c \
		srcs/raycaster2.c \
		srcs/free.c \
		srcs/bmp.c \
		srcs/sprites.c


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
	$(MAKE) -C libft re
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux re
	$(MAKE) -C minilibx-linux clean

$(NAME): re_libs
	$(GCC) $(SRCS) $(LIBFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all