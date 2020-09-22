/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:29:58 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/24 20:10:04 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne une copie de la
**	chaine de caractères donnée en argument, sans les
**	caractères spécifiés dans le set donné en argument
**	au début et à la fin de la chaine de caractères.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start])
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (end > 0)
	{
		if (ft_strchr(set, s1[end]) == NULL)
			break ;
		end--;
	}
	if (start > end || ft_strlen(s1) == 0)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, start, (end - start + 1)));
}
