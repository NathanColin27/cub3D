/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:40:31 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/05 16:07:28 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_data_init(t_main *m, t_camera *c, t_ray *r, int i)
{
	c->cam_x = 2 * i / (double)(m->map->res_x) - 1;
	set_pos(r->dir, c->dir->x + c->plane->x * c->cam_x,\
					c->dir->y + c->plane->y * c->cam_x);
	set_pos(r->delta, fabs(1 / r->dir->x), fabs(1 / r->dir->y));
	r->map_x = (int)c->pos->x;
	r->map_y = (int)c->pos->y;
	r->hit = 0;
	set_side_distance(c, r);
}

int		raycasting(t_main *m)
{
	int			i;
	t_camera	*c;
	t_ray		*r;

	i = 0;
	c = m->camera;
	r = m->ray;
	while (i++ < m->map->res_x)
	{
		ray_data_init(m, c, r, m->map->res_x - i);
		dda(m, r);
		wall_size(m, r, c);
		m->z_buff[i] = r->perp_wall_dist;
		get_wall_texture(c, r);
		get_wall_color(m, r, i);
		calc_textures(m, r, i);
	}
	sprite(m, c);
	if (m->bmp)
		save_bmp(m);
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->screen->img, 0, 0);
	return (1);
}

void	set_side_distance(t_camera *cam, t_ray *ray)
{
	if (ray->dir->x < 0)
	{
		ray->step->x = -1;
		ray->side_dist->x = (cam->pos->x - ray->map_x) * ray->delta->x;
	}
	else
	{
		ray->step->x = 1;
		ray->side_dist->x = (ray->map_x + 1.0 - cam->pos->x) * ray->delta->x;
	}
	if (ray->dir->y < 0)
	{
		ray->step->y = -1;
		ray->side_dist->y = (cam->pos->y - ray->map_y) * ray->delta->y;
	}
	else
	{
		ray->step->y = 1;
		ray->side_dist->y = (ray->map_y + 1.0 - cam->pos->y) * ray->delta->y;
	}
}

void	dda(t_main *m, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->side_dist->x < r->side_dist->y)
		{
			r->side_dist->x += r->delta->x;
			r->map_x += r->step->x;
			if (r->step->x == 1)
				r->side = 1;
			else if (r->step->x == -1)
				r->side = 0;
		}
		else
		{
			r->side_dist->y += r->delta->y;
			r->map_y += r->step->y;
			if (r->step->y == 1)
				r->side = 3;
			else if (r->step->y == -1)
				r->side = 2;
		}
		if (m->map->pattern[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	sprite(t_main *m, t_camera *c)
{
	int i;

	sprite_distance(m, c);
	sort_sprites(m);
	i = 0;
	while (i < m->map->sprite_number)
	{
		draw_sprite(m, i);
		i++;
	}
}
