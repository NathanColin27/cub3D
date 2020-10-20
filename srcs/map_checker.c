/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:58:31 by nathan            #+#    #+#             */
/*   Updated: 2020/10/20 23:03:37 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		set_start_pos(t_main *m)
{
	char dir;

	dir = m->map.start_direction;
	set_pos(&m->camera.pos, m->map.start_x + 0.5, m->map.start_y + 0.5);
	if (dir == 'N')
	{
		set_pos(&m->camera.dir, 0, -1);
		set_pos(&m->camera.plane, -FOV, 0);
	}
	else if (dir == 'S')
	{
		set_pos(&m->camera.dir, 0, 1);
		set_pos(&m->camera.plane, FOV, 0);
	}
	else if (dir == 'E')
	{
		set_pos(&m->camera.dir, 1, 0);
		set_pos(&m->camera.plane, 0, -FOV);
	}
	else if (dir == 'W')
	{
		set_pos(&m->camera.dir, -1, 0);
		set_pos(&m->camera.plane, 0, FOV);
	}
	return (1);
}

int		set_sprite(t_main *m)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	if (!(m->sprites = (t_sprite *)malloc(sizeof(t_sprite)\
						* m->map.sprite_number)))
		error("couldn't initialize sprite struct");
	while (y < m->map.height)
	{
		x = 0;
		while (x < ((int)ft_strlen(m->map.pattern[y])))
		{
			if (m->map.pattern[y][x] == '2')
			{
				m->sprites[i].x = x;
				m->sprites[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		elem_type(t_map *map, int x, int y)
{
	char elem;

	elem = map->pattern[y][x];
	if (elem == 'X')
		return (1);
	else if (elem == '1')
		return (2);
	else if (elem == '2' || elem == '0')
		return (3);
	else if (elem == 'N' || elem == 'S' || elem == 'E' || elem == 'W')
	{
		if (map->start_x == 0 && map->start_y == 0)
		{
			map->start_x = x;
			map->start_y = y;
			map->start_direction = elem;
		}
		else if (map->start_x != x || map->start_y != y)
			error("Start position declared more than once");
		return (4);
	}
	return (0);
}

void	get_map_height(t_map *map)
{
	int i;

	i = 0;
	while (map->pattern[i])
		i++;
	map->height = i;
}

void	check_adjacent_elem(t_map *map, int x, int y)
{
	int i;
	int j;

	if (map->pattern[y][x] == '2')
		map->sprite_number++;
	i = x - 1;
	while (i <= x + 1)
	{
		j = y - 1;
		while (j <= y + 1)
		{
			if (map->pattern[j][i] == '\0' || map->pattern[j][i] == 'X')
				error("map isn't totaly surrounded by walls");
			j++;
		}
		i++;
	}
}

int		map_check(t_main *m)
{
	int x;
	int y;

	y = 0;
	while (y < m->map.height)
	{
		x = 0;
		while (x < ((int)ft_strlen(m->map.pattern[y])))
		{
			if (!elem_type(&m->map, x, y))
				error("Unrecognized objet in map");
			if ((y == 0 || y == m->map.height - 1) \
				&& elem_type(&m->map, x, y) > 2)
				error("Map isn't closed on top or bottom wall");
			if (elem_type(&m->map, x, y) >= 3)
				check_adjacent_elem(&m->map, x, y);
			x++;
		}
		y++;
	}
	set_sprite(m);
	set_start_pos(m);
	return (0);
}
