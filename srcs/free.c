/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:20:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/08 16:35:51 by ncolin           ###   ########.fr       */
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
	if (c->pos)
		free(c->pos);
	if (c->plane)
		free(c->plane);
	if (c->dir)
		free(c->dir);
	if (c->x_dir)
		free(c->x_dir);
}

void	free_all(t_main *m)
{
	ft_free_map(m->map);
	ft_free_ray(m->ray);
	ft_free_camera(m->camera);
	ft_free_sprites(m->sprites);
	if (m->z_buff)
		free(m->z_buff);
}
