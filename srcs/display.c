/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/29 14:53:55 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		windows(t_main *m)
{
	mlx_hook(m->mlx_win, X_EVENT_KEY_PRESS, 1L<<0, key_press, m);
	mlx_hook(m->mlx_win, X_EVENT_KEY_RELEASE, 1L<<1, key_release, m);
	mlx_hook(m->mlx_win, X_EVENT_KEY_EXIT, 0L<<17, exit_pressed, m);
	mlx_loop_hook(m->mlx_ptr, main_loop, m);
	mlx_loop(m->mlx_ptr);
	return (EXIT_SUCCESS);
}

int		main_loop(t_main *m)
{
	t_camera	*c;
	static int	update;

	c = m->camera;
	update = 1;
	if (update)
	{
		raycasting(m);
		update = 0;
	}
	if (!c->move_dir || !c->rot_dir)
		update = 0;
	if (c->rot_dir)
		update = rotate_cam(m);
	if (c->move_dir)
		update = move_cam(m);
	return (0);
}

int		rotate_cam(t_main *m)
{
	t_camera	*c;
	double		rot;

	c = m->camera;
	rot = ROT_SPEED * c->rot_dir;
	set_pos(c->plane, cos(rot) * c->plane->x - sin(rot) * c->plane->y,\
						sin(rot) * c->plane->x + cos(rot) * c->plane->y);
	set_pos(c->dir, cos(rot) * c->dir->x - sin(rot) * c->dir->y,\
						sin(rot) * c->dir->x + cos(rot) * c->dir->y);
	return (1);
}

int		move_cam(t_main *m)
{
	double		new_x;
	double		new_y;
	t_camera	*c;

	c = m->camera;
	new_x = c->pos->x + c->dir->x * SPEED * c->move_dir;
	new_y = c->pos->y + c->dir->y * SPEED * c->move_dir;
	if (m->map->pattern[(int)new_y][(int)new_x] != '1')
		set_pos(c->pos, new_x, new_y);
	return (1);
}
