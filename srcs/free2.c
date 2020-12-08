/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:30:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/08 13:35:15 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_map(t_map *m)
{
	free_text_path(m);
	if (m->pattern)
		ft_free_array(m->pattern);
}

void	ft_free_sprites(t_sprite *s)
{
	if (s)
		free(s);
}

void	ft_free_ray(t_ray *r)
{
	free(r->dir);
	free(r->delta);
	free(r->side_dist);
	free(r->step);
}

void	ft_free_img(t_img *img)
{
	if (img->addr)
		free(img->addr);
	if (img->img)
		free(img->img);
}
