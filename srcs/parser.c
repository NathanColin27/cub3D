/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:39:34 by ncolin            #+#    #+#             */
/*   Updated: 2020/09/23 11:03:20 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	int fd;
	int ret;
	char *buff;
	t_map_data data;

	valid_args(ac);
	valid_extension(av[1]);
	data_init(&data);
	fd = open(av[1], O_RDONLY);
	
	while ((ret = get_next_line(fd, &buff)) >= 0 && !is_map_start(buff))
	{
		printf("%s\n", buff);
		parse_map_data(buff, &data);
		free(buff);
	}
	
	if(valid_map_data(&data))
		printf("map ok\n");
	parse_map_pattern(buff, &data, fd);
	map_check(&data);

	printf("res_x %d\n", data.res_x);
	printf("res_y %d\n", data.res_y);
	printf("texture_north %s\n", data.texture_north);
	printf("texture_south %s\n", data.texture_south);
	printf("texture_east %s\n", data.texture_east);
	printf("texture_west %s\n", data.texture_west);
	printf("texture_sprite %s\n", data.texture_sprite);
	printf("floor_color %d\n", data.floor_color);
	printf("ceiling_color %d\n", data.ceiling_color);
	printf("start x %d, start y %d\n", data.start_x, data.start_y);
	printf("start dir %c\n", data.start_direction);
	printf("map_height %d\n", data.height);
	printf("sprite number %d\n", data.sprite_number);
	for (int i = 0; i < data.sprite_number; i++)
	{
		printf("Sprite number %d --> x = %d, y = %d\n", i + 1, data.sprites[i].x, data.sprites[i].y);
	}
	
	close(fd);
	
	return (0); 
}