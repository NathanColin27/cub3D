/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:38:13 by nathan            #+#    #+#             */
/*   Updated: 2020/12/02 23:48:56 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_main *m)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		m->camera->move_dir_y = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		m->camera->move_dir_y = -1;
	if (keycode == KEY_LEFT)
		m->camera->rot_dir = 1;
	else if (keycode == KEY_RIGHT)
		m->camera->rot_dir = -1;
	if (keycode == KEY_A)
		m->camera->move_dir_x = 1;
	else if (keycode == KEY_D)
		m->camera->move_dir_x = -1;
	return (0);
}

int		key_release(int keycode, t_main *m)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		m->camera->move_dir_y = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		m->camera->move_dir_y = 0;
	else if (keycode == KEY_LEFT)
		m->camera->rot_dir = 0;
	else if (keycode == KEY_RIGHT)
		m->camera->rot_dir = 0;
	else if (keycode == KEY_A)
		m->camera->move_dir_x = 0;
	else if (keycode == KEY_D)
		m->camera->move_dir_x = 0;
	else if (keycode == KEY_ESC)
		exit_pressed(m);
	return (1);
}

int		exit_pressed(t_main *m)
{
	mlx_destroy_window(m->mlx_ptr, m->mlx_win);
	free_all(m);
	exit(0);
	return (1);
}
