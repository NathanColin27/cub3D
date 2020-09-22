/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:54:04 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 11:03:38 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcpy() function copies up to size - 1 characters from the
** NUL-terminated string src to dst, NUL-terminating the result.
** The source and destination strings should not overlap, as the behavior
**is undefined.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < size)
	{
		ft_memcpy(dst, (void *)src, src_len + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, (void *)src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}
