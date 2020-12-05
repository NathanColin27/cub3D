/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:31:15 by ncolin            #+#    #+#             */
/*   Updated: 2020/12/05 17:20:18 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	write_header(t_main *m, unsigned char header[54], int fd)
{
	unsigned int	*size;
	unsigned int	*width;
	unsigned int	*height;

	header[0] = 'B';
	header[1] = 'M';
	header[10] = 54;
	header[14] = 40;
	header[26] = 1;
	header[28] = 32;
	size = (unsigned int *)&header[2];
	*size = 54 + ((m->map->res_x * sizeof(t_pxl)) * m->map->res_y);
	width = (unsigned int *)&header[18];
	*width = m->map->res_x;
	height = (unsigned int *)&header[22];
	*height = m->map->res_y;
	write(fd, header, 54);
}

void	write_bmp(t_main *m, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = m->map->res_x * (m->map->res_y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < m->map->res_x)
		{
			buffer[0] = (unsigned char)(m->screen->addr[i] % 256);
			buffer[1] = (unsigned char)(m->screen->addr[i] / 256 % 256);
			buffer[2] = (unsigned char)(m->screen->addr[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * m->map->res_x;
	}
}

void	save_bmp(t_main *m)
{
	int						fd;
	static unsigned char	header[54];

	if ((fd = open("cube.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR\
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
		error(m,"couldn't create bmp");
	write_header(m, header, fd);
	write_bmp(m, fd);
	close(fd);
	m->bmp = 0;
	write(1, "Screenshot saved\n", 18);
	exit(0);
}
