/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/20 22:28:18 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		windows(t_main *main)
{
	t_window	window;

	if ((window.ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((window.win = mlx_new_window(window.ptr\
	, main->map.res_x, main->map.res_y, "Cub3D")) == NULL)
		return (EXIT_FAILURE);
	main->window = window;
	mlx_hook(window.win, X_EVENT_KEY_PRESS, 0, key_press, main);
	mlx_hook(window.win, X_EVENT_KEY_RELEASE, 0, key_release, main);
	mlx_hook(window.win, X_EVENT_KEY_EXIT, 0, exit_pressed, main);
	mlx_loop_hook(window.ptr, main_loop, main);
	mlx_loop(window.ptr);
	return (EXIT_SUCCESS);
}

int		main_loop(t_main *main)
{
	t_camera	*c;
	static int	update;

	c = &main->camera;
	update = 1;
	if (update)
	{
		raycasting(main);
		update = 0;
	}
	if (!c->move_dir || !c->rot_dir)
		update = 0;
	if (c->rot_dir)
		update = rotate_cam(main);
	if (c->move_dir)
		update = move_cam(main);
	return (0);
}

int		rotate_cam(t_main *main)
{
	t_camera	*c;
	double		rot;

	c = &main->camera;
	rot = ROT_SPEED * c->rot_dir;
	set_pos(&c->plane, cos(rot) * c->plane.x - sin(rot) * c->plane.y,\
						sin(rot) * c->plane.x + cos(rot) * c->plane.y);
	set_pos(&c->dir, cos(rot) * c->dir.x - sin(rot) * c->dir.y,\
						sin(rot) * c->dir.x + cos(rot) * c->dir.y);
	return (1);
}

int		move_cam(t_main *main)
{
	double		new_x;
	double		new_y;
	t_camera	*c;

	c = &main->camera;
	new_x = c->pos.x + c->dir.x * SPEED * c->move_dir;
	new_y = c->pos.y + c->dir.y * SPEED * c->move_dir;
	if (main->map.pattern[(int)new_y][(int)new_x] != '1')
		set_pos(&c->pos, new_x, new_y);
	return (1);
}
