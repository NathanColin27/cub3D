/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:14:59 by nathan            #+#    #+#             */
/*   Updated: 2020/10/20 23:24:32 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void	pxl_to_img(t_main *main, int x, int y, int color)
{
	main->screen.addr[x + (y * main->map.res_x)] = color;
}

void	ft_swap(float *a, float *b)
{
	float temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	exit(0);
}
