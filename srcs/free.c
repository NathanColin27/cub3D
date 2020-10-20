/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:20:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/20 22:57:04 by nathan           ###   ########.fr       */
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
