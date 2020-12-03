/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:39:34 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/03 19:21:54 by nathan           ###   ########.fr       */
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
	if (valid_color(m->map) && valid_file(m->map) && valid_res(m->map))
		parse_map_pattern(buff, m->map, fd);
	free(buff);
	map_check(m);
	close(fd);
}
