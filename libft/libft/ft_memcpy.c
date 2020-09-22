/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:35:22 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 14:32:39 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	The memcpy() function copies n bytes from memory area src to memory
**	area dst. If dst and src overlap, behavior is undefined. Applications
**	in which dst and src might overlap should use memmove(3) instead.
*/

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char *s;

	if (!dst && !src)
		return (0);
	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
