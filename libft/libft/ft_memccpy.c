/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:26:30 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 09:41:21 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char)
** occurs in the string src, the copy stops and a pointer to the byte after
** the copy of c in the string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
** The source and destination strings should not overlap,
** as the behavior is undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	while (n-- > 0)
	{
		if ((*d++ = *s++) == (char)c)
			return (d);
	}
	return (NULL);
}
