/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:05:53 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/09 12:02:28 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse(t_main *m, int fd)
{
	int		ret;
	char	*buff;

	while ((ret = get_next_line(fd, &buff)) >= 0 && !is_map_start(m, buff))
	{
		parse_map_data(m, buff, m->map);
		free(buff);
	}
	if (valid_color(m, m->map) && valid_file(m, m->map) && valid_res(m, m->map))
		parse_map_pattern(m, buff, m->map, fd);
	free(buff);
	map_check(m);
	close(fd);
}

int		windows(t_main *m)
{
	mlx_hook(m->mlx_win, X_EVENT_KEY_PRESS, 1L << 0, key_press, m);
	mlx_hook(m->mlx_win, X_EVENT_KEY_RELEASE, 1L << 1, key_release, m);
	mlx_hook(m->mlx_win, X_EVENT_KEY_EXIT, 1L << 17, exit_pressed, m);
	mlx_loop_hook(m->mlx_ptr, main_loop, m);
	mlx_loop(m->mlx_ptr);
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_main	m;
	int		fd;

	data_init(&m);
	if (ac == 3 && ft_strncmp(av[2], "--save", 7) == 0)
		m.bmp = 1;
	if (ac == 2 || (ac == 3 && m.bmp))
	{
		valid_args(&m, ac);
		valid_extension(&m, av[1]);
		fd = open(av[1], O_RDONLY);
		parse(&m, fd);
		init_images(&m, m.map);
		windows(&m);
	}
	else
		error(&m, "args not valid");
	return (0);
}
