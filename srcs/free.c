/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:20:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/11/30 13:41:07 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

// void free_all(t_main *m)
// {
// 	ft_free_map();
// 	ft_free_player();
// 	ft_free_camera();
// 	ft_free_sprite();
// 	ft_free_map();
// }