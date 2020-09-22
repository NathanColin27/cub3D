/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:45 by ncolin            #+#    #+#             */
/*   Updated: 2020/07/03 19:50:47 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) != 0)
	{
		if (start < ft_strlen(s))
			while (i < len && *(s + start + i))
			{
				result[i] = *(s + start + i);
				i++;
			}
		result[i] = '\0';
	}
	return (result);
}

char		*ft_strchr(char const *str, int c)
{
	char a;

	if (!str)
		return (NULL);
	a = c;
	while (*str)
	{
		if (*str == a)
			return (char *)(str);
		str++;
	}
	if (*str == a)
		return (char *)(str);
	return (NULL);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (len + 1))))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
