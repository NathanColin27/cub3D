/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:58:54 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/21 10:39:04 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strrchr() function is identical to strchr(), except it locates
** the last occurrence of c.
*/

char	*ft_strrchr(char const *str, int c)
{
	char a;

	a = c;
	while (*str)
	{
		if (*str == a && (!ft_strrchr(str + 1, c)))
			return (char *)(str);
		str++;
	}
	if (*str == a)
		return (char *)(str);
	return (0);
}
