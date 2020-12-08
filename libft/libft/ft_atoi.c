/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:57:52 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/08 11:19:08 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The atoi() function converts the initial portion of the string pointed
**	to by str to int representation.
*/

#define MAXLONG 9223372036854775807

int				ft_atoi(const char *str)
{
	int		sign;
	long	total;
	int		total_int;

	sign = 1;
	total = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (total <= total * 10 + (*str - '0'))
		{
			total = total * 10 + (*str - '0');
			str++;
		}
		else
			return (sign == 1 ? (int)MAXLONG : (int)-MAXLONG - 1);
	}
	total_int = total;
	return (total_int * sign);
}
