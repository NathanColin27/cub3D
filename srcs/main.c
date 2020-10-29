/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:05:53 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/29 15:16:50 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_main m;
	int fd;

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
		if ((m.mlx_ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((m.mlx_win = mlx_new_window(m.mlx_ptr, m.map->res_x, m.map->res_y, "Cub3D")) == NULL)
			return (EXIT_FAILURE);
		init_textures(&m);
		windows(&m);
	}
	else
		error("args not valid");
	return (0);
}

/*
**         printf("res_x %d\n", main.map.res_x);
**         printf("res_y %d\n", main.map.res_y);
**         printf("texture_north %s\n", main.map.tex_n);
**         printf("texture_south %s\n", main.map.tex_s);
**         printf("texture_east %s\n", main.map.tex_e);
**         printf("texture_west %s\n", main.map.tex_w);
**         printf("texture_sprite %s\n", main.map.tex_sp);
**         printf("floor_color %d\n", main.map.floor_color);
**         printf("ceiling_color %d\n", main.map.ceiling_color);
**         printf("start x %d, start y %d\n",\
**			 main.map.start_x, main.map.start_y);
**         printf("start dir %c\n", main.map.start_direction);
**         printf("map_height %d\n", main.map.height);
**         printf("sprite number %d\n", main.map.sprite_number);
**         for (int i = 0; i < main.map.sprite_number; i++)
**         {
**         	printf("Sprite number %d --> x = %d, y = %d\n",\
**			 i + 1, main.sprites[i].x, main.sprites[i].y);
**         }
*/
