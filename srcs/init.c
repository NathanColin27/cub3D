/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:14:20 by nathan            #+#    #+#             */
/*   Updated: 2020/12/08 15:58:34 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		init_buffer(t_main *m)
{
	int i;

	i = 0;
	// if (!(m->buff = ft_calloc(m->map->res_y, sizeof(int *))))
	// 	error(m, "Buff init failed");
	// while (i < m->map->res_y)
	// {
	// 	if (!(m->buff[i] = ft_calloc(m->map->res_x, sizeof(int))))
	// 		error(m, "Buff init failed");
	// 	i++;
	// }
	if (!(m->z_buff = malloc((m->map->res_x + 1) * sizeof(double))))
		error(m, "Z_buff init failed");
	return (1);
}

int		init_camera(t_camera *camera)
{
	if (!(camera->pos = malloc(sizeof(t_pos))))
		return (0);
	if (!(camera->dir = malloc(sizeof(t_pos))))
		return (0);
	if (!(camera->x_dir = malloc(sizeof(t_pos))))
		return (0);
	if (!(camera->plane = malloc(sizeof(t_pos))))
		return (0);
	camera->move_dir_x = 0;
	camera->move_dir_y = 0;
	camera->rot_dir = 0;
	return (1);
}

void	init_map(t_map *map)
{
	map->res_x = 0;
	map->res_y = 0;
	map->sprite_number = 0;
	map->ceiling_color = 0;
	map->floor_color = 0;
	map->start_direction = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->height = 0;
	map->tex_n = NULL;
	map->tex_s = NULL;
	map->tex_e = NULL;
	map->tex_w = NULL;
	map->tex_sp = NULL;
	map->pattern = NULL;
}

int		init_ray(t_ray *ray)
{
	if (!(ray->dir = malloc(sizeof(t_pos))))
		return (0);
	if (!(ray->delta = malloc(sizeof(t_pos))))
		return (0);
	if (!(ray->side_dist = malloc(sizeof(t_pos))))
		return (0);
	if (!(ray->step = malloc(sizeof(t_pos))))
		return (0);
	ray->id = 0;
	ray->side = 0;
	ray->hit = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->wall_size = 0;
	ray->wall_start = 0;
	ray->wall_end = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->perp_wall_dist = 0;
	ray->wall_x = 0;
	ray->tex_step = 0;
	ray->tex_pos = 0;
	return (1);
}

int		data_init(t_main *m)
{
	if (!(m->map = malloc(sizeof(t_map))))
		return (0);
	if (!(m->camera = malloc(sizeof(t_camera))))
		return (0);
	if (!(m->screen = malloc(sizeof(t_img))))
		return (0);
	if (!(m->ray = malloc(sizeof(t_ray))))
		return (0);
	m->bmp = 0;
	m->sprites = NULL;
	m->buff = NULL;
	m->z_buff = NULL;
	m->mlx_ptr = NULL;
	m->mlx_win = NULL;
	init_camera(m->camera);
	init_ray(m->ray);
	init_map(m->map);
	return (1);
}
