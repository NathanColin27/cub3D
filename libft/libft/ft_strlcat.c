/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:31:11 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 11:08:49 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strlcat() function appends the NUL-terminated string src to the end
**	of dst.  It will append at most size - strlen(dst) - 1 bytes,
**	NUL-terminating the result.
**	The source and destination strings should not overlap, as the behavior
**	is undefined.
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		total_len;
	size_t		dest_len;

	d = dst;
	s = src;
	total_len = size;
	while (total_len-- && *d != '\0')
		d++;
	dest_len = d - dst;
	total_len = size - dest_len;
	if (total_len == 0)
		return (dest_len + ft_strlen(s));
	while (*s)
	{
		if (total_len != 1)
		{
			*d++ = *s;
			total_len--;
		}
		s++;
	}
	*d = '\0';
	return (dest_len + (s - src));
}
