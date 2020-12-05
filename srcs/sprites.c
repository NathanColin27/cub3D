/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:58:09 by nathan            #+#    #+#             */
/*   Updated: 2020/12/05 16:12:19 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sort_sprites(t_main *m)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < m->map->sprite_number)
	{
		j = 0;
		while (j < m->map->sprite_number - i - 1)
		{
			if (m->sprites[j].distance < m->sprites[j + 1].distance)
			{
				tmp = m->sprites[j];
				m->sprites[j] = m->sprites[j + 1];
				m->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sprite_distance(t_main *m, t_camera *c)
{
	int i;

	i = 0;
	while (i < m->map->sprite_number)
	{
		m->sprites[i].distance = (c->pos->x - m->sprites[i].x) *
									(c->pos->x - m->sprites[i].x) +
										(c->pos->y - m->sprites[i].y) *
											(c->pos->y - m->sprites[i].y);
		i++;
	}
}

void	sprite_drawing_calculations(t_main *m, t_sprite_data *sprite)
{
	sprite->inv_det = 1.0 / (m->camera->plane->x * m->camera->dir->y -
			m->camera->dir->x * m->camera->plane->y);
	sprite->transform_x = -sprite->inv_det * (m->camera->dir->y *
			sprite->pos_x - m->camera->dir->x * sprite->pos_y);
	sprite->transform_y = sprite->inv_det * (-m->camera->plane->y *
			sprite->pos_x + m->camera->plane->x * sprite->pos_y);
	sprite->screen_x = (int)((m->map->res_x / 2) *
			(1 + sprite->transform_x / sprite->transform_y));
	sprite->h = abs((int)(m->map->res_y / sprite->transform_y));
	sprite->start_y = -sprite->h / 2 + m->map->res_y / 2;
	if (sprite->start_y < 0)
		sprite->start_y = 0;
	sprite->end_y = sprite->h / 2 + m->map->res_y / 2;
	if (sprite->end_y >= m->map->res_y)
		sprite->end_y = m->map->res_y - 1;
	sprite->w = abs((int)(m->map->res_y / sprite->transform_y));
	sprite->start_x = -sprite->w / 2 + sprite->screen_x;
	if (sprite->start_x < 0)
		sprite->start_x = 0;
	sprite->end_x = sprite->w / 2 + sprite->screen_x;
	if (sprite->end_x >= m->map->res_x)
		sprite->end_x = m->map->res_x;
}

void	draw_vertical_stripe(t_main *m, t_sprite_data *sprite, int stripe)
{
	int				y;
	int				tex_x;
	int				tex_y;
	int				d;
	unsigned int	color;

	tex_x = ((int)(256 * (stripe - (-sprite->w / 2 + sprite->screen_x)) *
				TEX_WIDTH / sprite->w)) / 256;
	if (sprite->transform_y > 0 && stripe > 0 && stripe < m->map->res_x &&
			sprite->transform_y < m->z_buff[stripe])
	{
		y = sprite->start_y + 5;
		while (y < sprite->end_y)
		{
			d = (y) * 256 - m->map->res_y * 128 + sprite->h * 128;
			tex_y = ((d * TEX_HEIGHT) / sprite->h) / 256;
			color = m->tex[4].addr[TEX_HEIGHT * tex_y + tex_x];
			if ((color & 0x00FFFFFF) != 0)
				pxl_to_img(m, stripe, y, color);
			y++;
		}
	}
}

void	draw_sprite(t_main *m, int i)
{
	t_sprite_data	sprite;
	int				stripe;

	sprite.pos_x = m->sprites[i].x - m->camera->pos->x;
	sprite.pos_y = m->sprites[i].y - m->camera->pos->y;
	sprite_drawing_calculations(m, &sprite);
	stripe = sprite.start_x;
	while (stripe < sprite.end_x)
	{
		draw_vertical_stripe(m, &sprite, stripe);
		stripe++;
	}
}
