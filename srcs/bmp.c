/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:31:15 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/17 16:49:31 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void bmp_header(t_main *m, unsigned char header[54])
{
    unsigned int	*size;
	unsigned int	*width;
	unsigned int	*height;

    header[0] = 66;
	header[1] = 77;
	header[10] = 54;
	header[14] = 40;
	header[26] = 1;
	header[28] = 24;

    size = (unsigned int *)&header[2];
	*size = 54 + ((m->map.res_x * sizeof(t_pxl)) * m->map.res_y);
	width = (unsigned int *)&header[18];
	*width = m->map.res_x;
	height = (unsigned int *)&header[22];
	*height = m->map.res_y;
}

unsigned char	get_g(unsigned int trgb)
{
	return ((trgb & 0x0000ff00) / pow(16, 2));
}

unsigned char	get_r(unsigned int trgb)
{
	return ((trgb & 0x00ff0000) / pow(16, 4));
}

unsigned char	get_b(unsigned int trgb)
{
	return (trgb & 0x000000ff);
}

void parse_screen(t_main *m, t_pxl screen[m->map.res_y][m->map.res_x])
{
    int x;
    int y;
    unsigned int color;

    y = m->map.res_y - 2;
    while(y > 1)
    {
        x = 0;
        while(x < m->map.res_x)
        {
            color = get_pxl(m->screen , x, y);
            screen[y][x].r = get_r(color); 
            screen[y][x].g = get_g(color);
            screen[y][x].b = get_b(color);
            x++;
        }
        y--;
    }
}

unsigned int get_pxl(t_img screen, int x, int y)
{
    unsigned int color;
    int *ptr;

    ptr = screen.addr + x + (y * screen.line_size);
    color = *(unsigned int *)ptr;
    return (color);
}


void save_bmp(t_main *m)
{
    int fd;
    int y;
    static unsigned char header[54];
    unsigned int pxl_bytes_per_row;
    write(1, "test", 5);
    t_pxl   screen[m->map.res_y][m->map.res_x];
    

    y = 0;
    if((fd = open("cube.bmp",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR \
            | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
        error("couldn't create bmp");
   
    bmp_header(m, header);
    write(fd, header, 54);
    parse_screen(m, screen);
    while(y < m->map.res_y - 1)
    {
        write(fd, screen[y], (m->map.res_x * sizeof(t_pxl))*4);
        y++;
    }
    close(fd);
    m->bmp = 0;
    error("bmp saved");
}