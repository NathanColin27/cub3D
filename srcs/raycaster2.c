/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:46:56 by nathan            #+#    #+#             */
/*   Updated: 2020/12/08 15:48:52 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_wall_texture(t_camera *c, t_ray *ray)
{
	if (ray->side <= 1)
		ray->wall_x = c->pos->y + ray->perp_wall_dist * ray->dir->y;
	else
		ray->wall_x = c->pos->x + ray->perp_wall_dist * ray->dir->x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 1 || ray->side == 2)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
}

void	get_wall_color(t_main *m, t_ray *ray, int x)
{
	int color;
	int y;

	ray->tex_step = 1.0 * TEX_HEIGHT / ray->wall_size;
	ray->tex_pos = (ray->wall_start - m->map->res_y / 2 \
					+ ray->wall_size / 2) * ray->tex_step;
	y = ray->wall_start;
	while (y < ray->wall_end + 1)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->tex_step;
		color = m->tex[ray->side].addr[TEX_HEIGHT * ray->tex_y + ray->tex_x];
		m->buff[y][x] = color;
		y++;
	}
}

void	calc_textures(t_main *m, t_ray *r, int x)
{
	int y;

	y = 0;
	while (y < r->wall_start)
	{
		pxl_to_img(m, x, y, m->map->ceiling_color);
		y++;
	}
	while (y < r->wall_end)
	{
		pxl_to_img(m, x, y, m->buff[y][x]);
		y++;
	}
	while (y < m->map->res_y)
		pxl_to_img(m, x, y++, m->map->floor_color);
}

void	wall_size(t_main *m, t_ray *r, t_camera *c)
{
	if (r->side <= 1)
		r->perp_wall_dist = (r->map_x - c->pos->x + \
							(1 - r->step->x) / 2) / r->dir->x;
	else
		r->perp_wall_dist = (r->map_y - c->pos->y + \
							(1 - r->step->y) / 2) / r->dir->y;
	r->wall_size = (int)(m->map->res_y / r->perp_wall_dist);
	r->wall_start = (-r->wall_size / 2 + (m->map->res_y / 2));
	if (r->wall_start <= 0)
		r->wall_start = 0;
	r->wall_end = r->wall_size / 2 + (m->map->res_y / 2);
	if (r->wall_end >= m->map->res_y)
		r->wall_end = m->map->res_y - 1;
}
