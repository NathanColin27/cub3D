/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:40:31 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/21 16:07:14 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		raycasting(t_main *main)
{
	int			i;
	t_camera	*c;
	t_ray		*r;

	i = 0;
	c = &main->camera;
	r = &main->ray;
	while (i++ < main->map.res_x)
	{
		c->cam_x = 2 * i / (double)(main->map.res_x) - 1;
		set_pos(&r->dir, c->dir.x + c->plane.x * c->cam_x, c->dir.y + c->plane.y * c->cam_x);
		set_pos(&r->delta, fabs(1 / r->dir.x), fabs(1 / r->dir.y));
		r->map_x = (int)c->pos.x;
		r->map_y = (int)c->pos.y;
		r->hit = 0;
		set_side_distance(c, r);
		dda(main, r);
		wall_size(main, r, c);
		main->z_buff[i] = r->perp_wall_dist;
		get_wall_texture(c, r);
		get_wall_color(main, r, i);
		calc_textures(main, r, c, i);
	}
	//sprite(main, c);
	mlx_put_image_to_window(main->window.ptr, main->window.win, main->screen.img_ptr, 0, 0);
	if (main->bmp)
		save_bmp(main);
	return (1);
}

void	get_wall_texture(t_camera *c, t_ray *ray)
{
	if (ray->side <= 1)
		ray->wall_x = c->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = c->pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 1 || ray->side == 2)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
}

void	get_wall_color(t_main *m, t_ray *ray, int x)
{
	int	color;
	int	y;

	ray->tex_step = 1.0 * TEX_HEIGHT / ray->wall_size;
	ray->tex_pos = (ray->wall_start - m->map.res_y / 2 + ray->wall_size / 2) * ray->tex_step;
	y = ray->wall_start;
	while (y < ray->wall_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->tex_step;
		color = m->tex[ray->side].addr[TEX_HEIGHT * ray->tex_y + ray->tex_x];
		m->buff[y][x] = color;
		y++;
	}
}

void	cast_floor_ceiling(t_main *m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m->map.res_y - 1)
	{
		x = 0;
		while (x < m->map.res_x - 1)
		{
			if (y > m->map.res_y / 2)
				m->buff[y][x] = m->map.floor_color;
			else
				m->buff[y][x] = m->map.ceiling_color;
			x++;
		}
		y++;
	}
}

void	calc_textures(t_main *m, t_ray *r, t_camera *c, int x)
{
	t_img	*texture;
	int		y;

	y = 0;
	while (y < r->wall_start)
		pxl_to_img(m, x, y++, m->map.ceiling_color);
	while (y < r->wall_end)
	{
		pxl_to_img(m, x, y, m->buff[y][x]);
		y++;
	}
	while (y < m->map.res_y)
		pxl_to_img(m, x, y++, m->map.floor_color);
}

void	set_side_distance(t_camera *cam, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (cam->pos.x - ray->map_x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - cam->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (cam->pos.y - ray->map_y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - cam->pos.y) * ray->delta.y;
	}
}

void	dda(t_main *main, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta.x;
			r->map_x += r->step.x;
			if (r->step.x == 1)
				r->side = 1;
			else if (r->step.x == -1)
				r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta.y;
			r->map_y += r->step.y;
			if (r->step.y == 1)
				r->side = 3;
			else if (r->step.y == -1)
				r->side = 2;
		}
		if (main->map.pattern[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	wall_size(t_main *main, t_ray *r, t_camera *c)
{
	if (r->side <= 1)
		r->perp_wall_dist = (r->map_x - c->pos.x + (1 - r->step.x) / 2) / r->dir.x;
	else
		r->perp_wall_dist = (r->map_y - c->pos.y + (1 - r->step.y) / 2) / r->dir.y;
	r->wall_size = (int)(main->map.res_y  / r->perp_wall_dist);
	r->wall_start = (-r->wall_size / 2 + (main->map.res_y / 2));
	if (r->wall_start <= 0)
		r->wall_start = 0;
	r->wall_end = r->wall_size / 2 + (main->map.res_y / 2);
	if (r->wall_end >= main->map.res_y)
		r->wall_end = main->map.res_y - 1;
}
