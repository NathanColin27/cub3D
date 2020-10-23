/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:38:13 by nathan            #+#    #+#             */
/*   Updated: 2020/10/23 10:58:50 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_main *m)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		m->camera->move_dir = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		m->camera->move_dir = -1;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		m->camera->rot_dir = 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		m->camera->rot_dir = -1;
	return (0);
}

int		key_release(int keycode, t_main *m)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		m->camera->move_dir = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		m->camera->move_dir = 0;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		m->camera->rot_dir = 0;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		m->camera->rot_dir = 0;
	else if (keycode == KEY_ESC)
		exit_pressed(m);
	return (1);
}

int		exit_pressed(t_main *m)
{
	mlx_destroy_window(m->mlx_ptr, m->mlx_win);
	exit(0);
	return (1);
}
