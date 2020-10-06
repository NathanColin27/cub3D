/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:39:34 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/06 23:13:18 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	int fd;
	int ret;
	char *buff;
	t_main main;

	valid_args(ac);
	valid_extension(av[1]);
	data_init(&main);
	fd = open(av[1], O_RDONLY);
	
	while ((ret = get_next_line(fd, &buff)) >= 0 && !is_map_start(buff))
	{
		printf("%s\n", buff);
		parse_map_data(buff, &main.map);
		free(buff);
	}
	
	if(valid_map_data(&main.map))
		printf("map ok\n");
	parse_map_pattern(buff, &main.map, fd);
	map_check(&main);

	printf("res_x %d\n", main.map.res_x);
	printf("res_y %d\n", main.map.res_y);
	printf("texture_north %s\n", main.map.texture_north);
	printf("texture_south %s\n", main.map.texture_south);
	printf("texture_east %s\n", main.map.texture_east);
	printf("texture_west %s\n", main.map.texture_west);
	printf("texture_sprite %s\n", main.map.texture_sprite);
	printf("floor_color %d\n", main.map.floor_color);
	printf("ceiling_color %d\n", main.map.ceiling_color);
	printf("start x %d, start y %d\n", main.map.start_x, main.map.start_y);
	printf("start dir %c\n", main.map.start_direction);
	printf("map_height %d\n", main.map.height);
	printf("sprite number %d\n", main.map.sprite_number);
	for (int i = 0; i < main.map.sprite_number; i++)
	{
		
		printf("Sprite number %d --> x = %d, y = %d\n", i + 1, main.sprites[i].x, main.sprites[i].y);
	}
	close(fd);
	windows(&main);
	
	return (0); 
}