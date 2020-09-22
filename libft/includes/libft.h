/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:43:23 by ncolin            #+#    #+#             */
/*   Updated: 2020/09/21 11:21:52 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;



/*  _     ___ ____  _____ _____ 
** | |   |_ _| __ )|  ___|_   _|
** | |    | ||  _ \| |_    | |  
** | |___ | || |_) |  _|   | |  
** |_____|___|____/|_|     |_|  
*/                              


/*
**		char
*/

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

int 				ft_isspace(int c);
/*
** string
*/

char				**ft_split(char const *str, char sep);

char				*ft_strchr(char const *str, int c);

char    			*ft_strcpy (char *dest, const char *src);

char				*ft_strdup(const char *s1);

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);

size_t				ft_strlen(const char *str);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strnstr(const char *str, const char *find, size_t len);

char				*ft_strrchr(char const *s, int c);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
**	mem
*/

void				ft_bzero(void *s, size_t n);

void				*ft_calloc(size_t count, size_t size);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, void const *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memset(void *b, int c, size_t len);

/*
** others
*/

char				*ft_itoa(int n);

int					ft_atoi(const char *str);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** put
*/

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

/*
** Bonus
*/

void				ft_lstadd_back(t_list **alst, t_list *new);

void				ft_lstadd_front(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstlast(t_list *lst);

t_list				*ft_lstnew(void *content);

int					ft_lstsize(t_list *lst);

/*
**   ____ _____ _____   _   _ _______  _______   _     ___ _   _ _____ 
**  / ___| ____|_   _| | \ | | ____\ \/ /_   _| | |   |_ _| \ | | ____|
** | |  _|  _|   | |   |  \| |  _|  \  /  | |   | |    | ||  \| |  _|  
** | |_| | |___  | |   | |\  | |___ /  \  | |   | |___ | || |\  | |___ 
**  \____|_____| |_|   |_| \_|_____/_/\_\ |_|   |_____|___|_| \_|_____|                                                                  
*/


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

// # ifndef OPEN_MAX
// #  define OPEN_MAX 10240
// # endif

int		ft_del_tab(char **tab);
int		get_next_line(int fd, char **line);

#endif
