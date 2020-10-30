/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:52:46 by nathan            #+#    #+#             */
/*   Updated: 2020/10/30 12:24:08 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		valid_args(int ac)
{
	if (ac < 2)
	{
		error("Please provide a map");
		return (0);
	}
	else if (ac > 3)
	{
		error("Too much arguments");
		return (0);
	}
	return (1);
}

int		valid_res(t_map *map)
{
	if (map->res_x <= 0 || map->res_y <= 0)
		error("Wrong resolution");
	if (map->res_x > MAX_WIDTH)
		map->res_x = MAX_WIDTH;
	if (map->res_y > MAX_HEIGHT)
		map->res_y = MAX_HEIGHT;
	if (map->res_x < MIN_WIDTH)
		map->res_x = MIN_WIDTH;
	if (map->res_y < MIN_HEIGHT)
		map->res_y = MIN_HEIGHT;
	return (1);
}

int		valid_color(t_map *map)
{
	if (map->ceiling_color < 0)
		error("Wrong ceiling color");
	else if (map->floor_color < 0)
		error("Wrong floor color");
	return (1);
}

int		valid_extension(char *map_name)
{
	char *dot;

	dot = ft_strrchr(map_name, '.');
	if (dot && ft_strncmp(dot, ".cub", 5))
		error("Wrong file extension");
	if (open(map_name, O_RDONLY) == -1)
		error("Could'nt open file");
	return (1);
}

int		valid_file(t_map *map)
{
	if ((open(map->tex_n, O_RDONLY)) == -1)
		error("Could not open North texture");
	else if (open(map->tex_s, O_RDONLY) == -1)
		error("Could not open South texture");
	else if (open(map->tex_e, O_RDONLY) == -1)
		error("Could not open East texture");
	else if (open(map->tex_w, O_RDONLY) == -1)
		error("Could not open West texture");
	else if (open(map->tex_sp, O_RDONLY) == -1)
		error("Could not open Sprite texture");
	return (1);
}

int		valid_map_data(t_map *map)
{
	return ((valid_color(map) && valid_file(map) && valid_res(map)));
}
