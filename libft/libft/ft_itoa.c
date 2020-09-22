/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:17:32 by ncolin            #+#    #+#             */
/*   Updated: 2019/10/23 10:15:41 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
*/

static long	num_len(long n)
{
	long i;

	i = 1;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	a;
	size_t	len;

	len = ft_strlen((char *)str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	num = n;
	sign = (num < 0) ? 1 : 0;
	if (!(str = (char *)malloc(sizeof(char) * (num_len(num) + 1 + sign))))
		return (NULL);
	if (n < 0)
		num *= -1;
	if (n == 0)
		str[i++] = '0';
	while (num)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i++] = '\0';
	ft_strrev(str);
	return (str);
}
