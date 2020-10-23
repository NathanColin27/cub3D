/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:25:51 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/23 11:16:30 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void sort_sprites(t_main *m)
{
	int 		i;
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
				write(1, "swap", 5);
			}
			j++;
		}
		i++;
	}
	write(1, "out", 4);
}


void sprite_distance(t_main *m, t_camera *c)
{
    int i;

    i = 0;
    while (i < m->map->sprite_number)
    {
		m->sprites[i].distance = (c->pos->x - m->sprites[i].x) * \
                                    (c->pos->x - m->sprites[i].x) + \
                                        (c->pos->y - m->sprites[i].y) *\
                                            (c->pos->y - m->sprites[i].y);
        i++;
    }
	
}

void sprite(t_main *m, t_camera *c)
{
	sprite_distance(m, c);
	//sort_sprites(m);
}