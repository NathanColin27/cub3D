/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:20:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/03 19:06:32 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return (0);
}

int		ft_free_int_array(int **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return (0);
}

void	free_text_path(t_map *map)
{
	free(map->tex_n);
	free(map->tex_s);
	free(map->tex_e);
	free(map->tex_w);
	free(map->tex_sp);
	map->tex_n = NULL;
	map->tex_s = NULL;
	map->tex_e = NULL;
	map->tex_w = NULL;
	map->tex_sp = NULL;
}

void	ft_free_camera(t_camera *c)
{
	free(c->pos);
	free(c->plane);
	free(c->dir);
	free(c->x_dir);
}

void ft_free_map(t_map *m)
{
	free_text_path(m);
	ft_free_array(m->pattern);
}

void ft_free_sprites(t_sprite *s)
{
	free(s);
}

void ft_free_ray(t_ray *r)
{
	free(r->dir);
	free(r->delta);
	free(r->side_dist);
	free(r->step);
}

void free_all(t_main *m)
{
	ft_free_map(m->map);
	ft_free_ray(m->ray);
	ft_free_camera(m->camera);
	ft_free_sprites(m->sprites);
	ft_free_int_array(m->buff);
	// ft_free_screen(m->screen);
	free(m->z_buff);
}