/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:46:56 by nathan            #+#    #+#             */
/*   Updated: 2020/12/09 10:45:26 by ncolin           ###   ########.fr       */
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

void	calc_textures(t_main *m, t_ray *r, int x)
{
	int y;
	int color;

	y = 0;
	r->tex_step = 1.0 * TEX_HEIGHT / r->wall_size;
	r->tex_pos = (r->wall_start - m->map->res_y / 2 \
					+ r->wall_size / 2) * r->tex_step;
	while (y < r->wall_start)
	{
		pxl_to_img(m, x, y, m->map->ceiling_color);
		y++;
	}
	while (y < r->wall_end)
	{
		r->tex_y = (int)r->tex_pos & (TEX_HEIGHT - 1);
		r->tex_pos += r->tex_step;
		color = m->tex[r->side].addr[TEX_HEIGHT * r->tex_y + r->tex_x];
		pxl_to_img(m, x, y, color);
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
