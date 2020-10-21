/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:14:20 by nathan            #+#    #+#             */
/*   Updated: 2020/10/21 15:27:28 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#define T m->tex
#define UI unsigned int
#define ADDR mlx_get_data_addr

int		init_buffer(t_main *m)
{
	int i;

	i = 0;
	if (!(m->buff = ft_calloc(m->map.res_y, sizeof(int **))))
		error("Buff init failed");
	while (i < m->map.res_y)
	{
		if (!(m->buff[i] = ft_calloc(m->map.res_x, sizeof(int *))))
			error("Buff init failed");
		i++;
	}
	if (!(m->z_buff = ft_calloc(m->map.res_x, sizeof(double *))))
		error("Z_buff init failed");
	return (1);
}

void init_camera(t_camera *camera)
{	
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->dir.x = 0;
	camera->dir.y = 0;
	camera->move_dir = 0;
	camera->move_dir = 0;
	camera->rot_dir = 0;
	camera->move_dir = 0;
	camera->plane.x = 0;
	camera->plane.y = FOV;
}

void init_map(t_map *map)
{
	map->res_x = 0;
	map->res_y = 0;
	map->sprite_number = 0;
	map->ceiling_color = 0;
	map->floor_color = 0;
	map->start_direction = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->tex_n = NULL;
	map->tex_s = NULL;
	map->tex_e = NULL;
	map->tex_w = NULL;
	map->tex_sp = NULL;

}

void	data_init(t_main *m)
{	
	init_camera(&m->camera);
	init_map(&m->map);
	m->sprites = NULL;
	m->buff = NULL;
}

void	init_textures(t_main *m)
{
	init_buffer(m);
	T[0].img_ptr = XPM(&m->window.ptr, m->map.tex_n, &T[0].img_x, &T[0].img_y);
	T[1].img_ptr = XPM(&m->window.ptr, m->map.tex_s, &T[1].img_x, &T[1].img_y);
	T[2].img_ptr = XPM(&m->window.ptr, m->map.tex_e, &T[2].img_x, &T[2].img_y);
	T[3].img_ptr = XPM(&m->window.ptr, m->map.tex_w, &T[3].img_x, &T[3].img_y);
	T[4].img_ptr = XPM(&m->window.ptr, m->map.tex_sp, &T[4].img_x, &T[4].img_y);
	if (!T[0].img_ptr || !T[1].img_ptr ||\
		!T[2].img_ptr || !T[3].img_ptr || !T[4].img_ptr)
		error("Couldn't load textures");
	free_text_path(&m->map);
	T[0].addr = (UI *)ADDR(T[0].img_ptr, &T[0].bpp, &T[0].line_size, &T[0].endian);
	T[1].addr = (UI *)ADDR(T[1].img_ptr, &T[1].bpp, &T[1].line_size, &T[1].endian);
	T[2].addr = (UI *)ADDR(T[2].img_ptr, &T[2].bpp, &T[2].line_size, &T[2].endian);
	T[3].addr = (UI *)ADDR(T[3].img_ptr, &T[3].bpp, &T[3].line_size, &T[3].endian);
	T[4].addr = (UI *)ADDR(T[4].img_ptr, &T[4].bpp, &T[4].line_size, &T[4].endian);
	m->screen.img_ptr = mlx_new_image(&m->window.ptr, m->map.res_x, m->map.res_y);
	m->screen.addr = (unsigned int *)ADDR(m->screen.img_ptr, &m->screen.bpp, &m->screen.line_size, &m->screen.endian);
}
