/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:39:34 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/05 17:29:25 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse(t_main *m, int fd)
{
	int		ret;
	char	*buff;

	while ((ret = get_next_line(fd, &buff)) >= 0 && !is_map_start(buff))
	{
		parse_map_data(buff, m->map);
		free(buff);
	}
	if (valid_color(m, m->map) && valid_file(m, m->map) && valid_res(m, m->map))
		parse_map_pattern(m, buff, m->map, fd);
	free(buff);
	map_check(m);
	close(fd);
}
