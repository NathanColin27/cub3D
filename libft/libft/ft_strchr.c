/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:28:17 by ncolin            #+#    #+#             */
/*   Updated: 2020/09/23 10:15:35 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strchr() function locates the first occurrence of c
**	(converted to a char) in the string pointed to by s. The terminating null
**  character is considered to be part of the string; therefore if c is `\0',
**	the functions locate the terminating `\0'.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
		{
			return (0);
		}
		ptr++;
	}
	return (ptr);
}
