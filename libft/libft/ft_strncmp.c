/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:20:12 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/23 20:07:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strcmp() and strncmp() functions lexicographically compare the
**	null-terminated strings s1 and s2.
**
**	The strncmp() function compares not more than n characters.  Because
**	strncmp() is designed for comparing strings rather than binary data,
**	characters that appear after a `\0' character are not compared.
*/

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int			result;

	result = 0;
	while (!result && (*str1 || *str2) && n-- > 0)
	{
		result = (unsigned char)*str1 - (unsigned char)*str2;
		str1++;
		str2++;
	}
	return (result);
}
