/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:16:53 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 11:41:40 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strnstr() function locates the first occurrence of the null-terminated
**	string needle in the string haystack, where not more than len characters are
**	searched. Characters that appear after a `\0' character are not searched.
*/

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*find == '\0')
		return ((char*)str);
	while (str[i] && i < (int)len)
	{
		while (str[i + j] == find[j] && i + j < (int)len)
		{
			if (find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
