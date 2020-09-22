/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:40:32 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 09:50:53 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memchr() function locates the first occurrence of c
** (converted to an unsigned char) in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	char		a;

	a = (char)c;
	str = s;
	while (n-- > 0)
	{
		if (*str == a)
			return (void *)(str);
		str++;
	}
	return (0);
}
