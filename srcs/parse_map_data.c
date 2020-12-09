/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:06:55 by nathan            #+#    #+#             */
/*   Updated: 2020/12/09 12:22:23 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_res(char *line, t_map *map)
{
	int i;

	i = 0;
	if (line[i] != 'R')
		return (0);
	while (!ft_isdigit(line[i]))
		i++;
	map->res_x = ft_atoi(&line[i]);
	while (!ft_isspace(line[i]))
		i++;
	map->res_y = ft_atoi(&line[i]);
	return (1);
}

int		valid_descriptor(char a, char b)
{
	if (a == 'N' && b == 'O')
		return (1);
	else if (a == 'S' && b == 'O')
		return (1);
	else if (a == 'W' && b == 'E')
		return (1);
	else if (a == 'E' && b == 'A')
		return (1);
	else if (a == 'S' && b == ' ')
		return (1);
	else
		return (0);
}

int		parse_texture(t_main *m, char *line, t_map *map)
{
	int i;

	i = 1;
	if (line[0] == 'S' && line[1] == ' ')
	{
		while (ft_isspace(line[i]))
			i++;
		map->tex_sp = ft_strdup(&line[i]);
	}
	else if (line[2] != ' ')
		error(m, "TEXTURE : invalid line");
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (line[0] == 'N' && line[1] == 'O')
		map->tex_n = ft_strdup(&line[i]);
	else if (line[0] == 'S' && line[1] == 'O')
		map->tex_s = ft_strdup(&line[i]);
	else if (line[0] == 'W' && line[1] == 'E')
		map->tex_w = ft_strdup(&line[i]);
	else if (line[0] == 'E' && line[1] == 'A')
		map->tex_e = ft_strdup(&line[i]);
	return (1);
}

void	parse_colors(t_main *m, char *line, t_map *map)
{
	int i;
	int r;
	int g;
	int b;

	i = 0;
	while (line[i])
	{
		if (!ft_haschr(" 0123456789,FC", line[i]))
			error(m, "Wrong character found in Floor or Ceiling line");
		i++;
	}
	i = 1;
	i = ft_skip(m, line, i, 0);
	r = ft_atoi(&line[i]);
	i = ft_skip(m, line, i, r);
	g = ft_atoi(&line[i]);
	i = ft_skip(m, line, i, g);
	b = ft_atoi(&line[i]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error(m, "Incorrect RGB value (must be between 0 and 255)");
	if (line[0] == 'F')
		map->floor_color = rgb(r, g, b);
	else if (line[0] == 'C')
		map->ceiling_color = rgb(r, g, b);
}

void	parse_map_data(t_main *m, char *line, t_map *map)
{
	char *copy;

	copy = ft_strtrim(line, " \t\n\v\f\r");
	if (!copy[0])
	{
		free(copy);
		return ;
	}
	else if (copy[0] == 'R' && copy[1] == ' ')
		parse_res(copy, map);
	else if (valid_descriptor(copy[0], copy[1]))
		parse_texture(m, copy, map);
	else if (copy[0] == 'C' || copy[0] == 'F')
		parse_colors(m, copy, map);
	else
	{
		free(copy);
		error(m, "invalid line");
	}
	free(copy);
}
