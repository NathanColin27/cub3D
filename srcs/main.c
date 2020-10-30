/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:05:53 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/30 13:01:20 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		//_get_summary();
		valid_args(ac);
		valid_extension(av[1]);
		fd = open(av[1], O_RDONLY);
		parse(&m, fd);
		init_images(&m, m.map);
		windows(&m);
	}
	else
		error("args not valid");
	return (0);
}
