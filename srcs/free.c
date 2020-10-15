/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:20:41 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/15 16:23:06 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void free_text_path(t_map *map)
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