/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:39:34 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/20 23:10:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void parse(t_main *main, int fd)
{
	int		ret;
	char	*buff;
	while ((ret = get_next_line(fd, &buff)) >= 0 && !is_map_start(buff))
	{
		parse_map_data(buff, &main->map);
		free(buff);
	}
	if (valid_map_data(&main->map))
		parse_map_pattern(buff, &main->map, fd);
	map_check(main);
	close(fd);
}