/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/11/30 12:31:02 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (!c->move_dir_x || !c->move_dir_y || !c->rot_dir)
		update = 0;
	if (c->rot_dir)
		update = rotate_cam(m);
	if (c->move_dir_x)
		update = move_cam_x(m);
	if (c->move_dir_y)
		update = move_cam_y(m);
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

int		move_cam_y(t_main *m)
{
	double		new_x;
	double		new_y;
	t_camera	*c;

	c = m->camera;
	new_x = c->pos->x + c->dir->x * SPEED * c->move_dir_y;
	new_y = c->pos->y + c->dir->y * SPEED * c->move_dir_y;
	if (m->map->pattern[(int)new_y][(int)new_x] != '1' \
		&& m->map->pattern[(int)new_y][(int)new_x] != '2')
		set_pos(c->pos, new_x, new_y);
	else if (m->map->pattern[(int)c->pos->y][(int)new_x] != '1' \
		&& m->map->pattern[(int)c->pos->y][(int)new_x] != '2')
		set_pos(c->pos, new_x, c->pos->y);
	else if (m->map->pattern[(int)new_y][(int)c->pos->x] != '1' \
		&& m->map->pattern[(int)new_y][(int)c->pos->x] != '2')
		set_pos(c->pos, c->pos->x, new_y);
	return (1);
}

int		move_cam_x(t_main *m)
{
	double		new_x;
	double		new_y;
	t_camera	*c;

	c = m->camera;
	new_x = c->pos->x - c->dir->y * SPEED * 0.75 * c->move_dir_x;
	new_y = c->pos->y + c->dir->x * SPEED * 0.75 * c->move_dir_x;
	if (m->map->pattern[(int)new_y][(int)new_x] != '1' \
		&& m->map->pattern[(int)new_y][(int)new_x] != '2')
		set_pos(c->pos, new_x, new_y);
	else if (m->map->pattern[(int)c->pos->y][(int)new_x] != '1' \
		&& m->map->pattern[(int)c->pos->y][(int)new_x] != '2')
		set_pos(c->pos, new_x, c->pos->y);
	else if (m->map->pattern[(int)new_y][(int)c->pos->x] != '1' \
		&& m->map->pattern[(int)new_y][(int)c->pos->x] != '2')
		set_pos(c->pos, c->pos->x, new_y);
	return (1);
}
