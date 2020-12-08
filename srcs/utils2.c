/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:47:49 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/08 16:21:44 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_haschr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_skip(t_main *m, char *line, int i, int color)
{
	int found;

	found = 0;
	if (i == 1)
		found = 1;
	i += ft_strlen(ft_itoa(color));
	while (line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		else if (line[i] == ',' && found == 1)
			error(m, "COLOR LINE : Invalid format");
		else if (line[i] == ',' && found == 0)
		{
			found = 1;
			i++;
		}
		else if (ft_isdigit(line[i]) && found == 0)
			error(m, "COLOR LINE : Invalid format");
		else if (ft_isdigit(line[i]) && found == 1)
			return (i);
	}
	return (-1);
}
