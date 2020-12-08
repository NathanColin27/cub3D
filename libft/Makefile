CC = gcc

CCFLAGS = -Wall -Wextra -Werror 

NAME = libft.a

SRC =  	libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_isspace.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_putnbr_fd.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_strchr.c \
		libft/ft_strcpy.c \
		libft/ft_putendl_fd.c \
		libft/ft_strdup.c  \
		libft/ft_toupper.c \
		libft/ft_strlcpy.c \
		libft/ft_putstr_fd.c\
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlen.c \
		libft/ft_putchar_fd.c\
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_calloc.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_strrchr.c \
		libft/ft_split.c \
		libft/ft_substr.c \
		libft/ft_strtrim.c \
		libft/ft_tolower.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstadd_front_bonus.c  \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		\
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) includes/libft.h
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -I includes/ -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all

so: $(OBJ) includes/libft.h
	$(CC) -shared -fPIC -Wl,-soname,libft.so -o libft.so $(OBJ)
