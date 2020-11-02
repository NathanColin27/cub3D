/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:57:33 by nathan            #+#    #+#             */
/*   Updated: 2020/11/01 14:34:14 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void 	init_screen(t_main *m, t_map *mp)
{
	if ((m->mlx_ptr = mlx_init()) == NULL)
		error("mlx_ptr not initialized");
	if ((m->mlx_win = mlx_new_window(m->mlx_ptr, mp->res_x,\
								mp->res_y, "Cub3D")) == NULL)
		error("mlx_win not initialized");
	m->screen->img = mlx_new_image(m->mlx_ptr, mp->res_x, mp->res_y);
	m->screen->addr = ADDR(m->screen->img, &m->screen->bpp,\
							&m->screen->line_size, &m->screen->endian);
}

void	init_images(t_main *m, t_map *mp)
{	
	int i;
	
	init_screen(m, mp);
	init_buffer(m);
	m->tex[0].img = XPM(m->mlx_ptr, mp->tex_n, &m->tex[0].img_x, &m->tex[0].img_y);
	m->tex[1].img = XPM(m->mlx_ptr, mp->tex_s, &m->tex[1].img_x, &m->tex[1].img_y);
	m->tex[2].img = XPM(m->mlx_ptr, mp->tex_e, &m->tex[2].img_x, &m->tex[2].img_y);
	m->tex[3].img = XPM(m->mlx_ptr, mp->tex_w, &m->tex[3].img_x, &m->tex[3].img_y);
	m->tex[4].img = XPM(m->mlx_ptr, mp->tex_sp, &m->tex[4].img_x, &m->tex[4].img_y);
	if (!m->tex[0].img || !m->tex[1].img ||\
		!m->tex[2].img || !m->tex[3].img || !m->tex[4].img)
		error("Couldn't load textures");
	free_text_path(mp);
	i = -1;
	while(++i < 5)
		m->tex[i].addr = ADDR(m->tex[i].img, &m->tex[i].bpp,\
								 &m->tex[i].line_size, &m->tex[i].endian);
	// init_sprites
}
