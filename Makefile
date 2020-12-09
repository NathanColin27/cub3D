NAME =	cub3D

FLAGS = -Wall -Wextra -Werror -O2 -g

GCC = clang $(FLAGS)

SRC_PATH =	srcs/
SRC_NAME = 	main.c 				\
			error_handling.c	\
			init.c				\
			init2.c				\
			parse_map_data.c	\
			map_parser.c		\
			map_checker.c		\
			display.c			\
			keys.c				\
			utils.c				\
			utils2.c			\
			raycaster.c			\
			raycaster2.c		\
			free.c				\
			free2.c				\
			bmp.c				\
			sprites.c


SRCS =	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS =	$(SRCS:.c=.o)
INCLUDES =	includes/cub3d.h

MLX_PATH = -L./mlx
MLX_FLAGS = -framework OpenGL -framework AppKit
MLX = -lmlx

LIBFT_PATH = ./libft/
LIBFT = libft.a

V	= \xE2\x9C\x94

all: $(NAME) 

%.o: %.c
	@$(GCC) -c -o $@ $<

re_libs:
	@$(MAKE) -C libft re
	@$(MAKE) -C libft clean
	@echo "\033[32;1mlibft recompiled ${V}\033[0m"

$(NAME): re_libs
	@rm -rf cube.bmp
	@$(GCC) $(SRCS) $(LIBFT_PATH)$(LIBFT) $(MLX_PATH) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[32;1mcub3D compiled ${V}\033[0m"

norm:
	@norminette $(SRC_PATH) $(INCLUDES) $(LIBFT_PATH)

clean:
	@rm -rf *.o
	@echo "\033[32;1mCleaned cub3D ${V}\033[0m"

fclean: clean
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME)
	@$(MAKE) -C libft fclean
	@echo "\033[32;1mFully Cleaned cub3D ${V}\033[0m"

re: fclean all

.PHONY: re_libs all clean fclean re