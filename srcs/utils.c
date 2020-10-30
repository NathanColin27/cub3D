/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:14:59 by nathan            #+#    #+#             */
/*   Updated: 2020/10/30 12:56:38 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void	pxl_to_img(t_main *m, int x, int y, int color)
{
	m->screen->addr[x + (y * m->map->res_x)] = color;
}

void	error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	exit(0);
}

int		is_map_start(char *line)
{
	if (line[0] == '1' || line[0] == ' ')
		return (1);
	return (0);
}

int		rgb(int r, int g, int b)
{
	return (65536 * r + 256 * g + b);
}
