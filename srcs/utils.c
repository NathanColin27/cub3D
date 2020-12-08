/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:14:59 by nathan            #+#    #+#             */
/*   Updated: 2020/12/08 13:49:53 by ncolin           ###   ########.fr       */
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

void	error(t_main *m, char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	free_all(m);
	exit(0);
}

int		is_map_start(t_main *m, char *line)
{
	if (!m->map->res_x || !m->map->res_y || !m->map->tex_n || \
		!m->map->tex_s || !m->map->tex_sp || !m->map->tex_w || \
		!m->map->tex_w || !m->map->floor_color || !m->map->ceiling_color)
		return (0);
	if (line[0] == '1' || line[0] == ' ')
		return (1);
	return (0);
}

int		rgb(int r, int g, int b)
{
	return (65536 * r + 256 * g + b);
}
