NAME =	cub3D

FLAGS = -Wall -Wextra -Werror -O2

GCC = gcc 

SRCS = 	srcs/parser.c \
		srcs/error_handling.c \
		srcs/struct_init.c \
		srcs/parse_map_data.c \
		srcs/map_parser.c \
		srcs/map_checker.c \
		srcs/display.c \


OBJS =	$(SRCS:.c=.o)

INCLUDES =	includes/cub3d.h

OSNAME = $(shell uname)

ifeq ($(OSNAME),Darwin)
	MLX_PATH = 
	MLX_FLAGS = -L../mlx -lmlx -framework OpenGL -framework AppKit
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

$(NAME): 
	$(GCC) $(SRCS) $(LIBFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX) $(MLX_FLAGS) 

clean:
	@rm -rf *.o test

fclean: clean
	@rm -rf $(NAME)

re: fclean all