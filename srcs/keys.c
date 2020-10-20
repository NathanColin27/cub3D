/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:38:13 by nathan            #+#    #+#             */
/*   Updated: 2020/10/20 22:58:00 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_main *main)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		main->camera.move_dir = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		main->camera.move_dir = -1;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		main->camera.rot_dir = 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		main->camera.rot_dir = -1;
	return (0);
}

int		key_release(int keycode, t_main *main)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		main->camera.move_dir = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		main->camera.move_dir = 0;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		main->camera.rot_dir = 0;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		main->camera.rot_dir = 0;
	else if (keycode == KEY_ESC)
		exit_pressed(&main->window);
	return (1);
}

int		exit_pressed(t_window *window)
{
	mlx_destroy_window(window->ptr, window->win);
	exit(0);
	return (1);
}
