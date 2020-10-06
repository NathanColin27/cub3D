/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:51:35 by nathan            #+#    #+#             */
/*   Updated: 2020/10/03 23:21:38 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int delay_time = 3; // in millisec

int color_map_1(t_window window, int w, int h)
{
    int x;
    int y;
    int color;

    x = w;
    while (x--)
    {
        y = h;
        while (y--)
        {
            color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
            mlx_pixel_put(window.ptr, window.win, x, y, color);
        }
    }
    return 0;
}

void set_point(t_2D_point *point, int x, int y)
{
    point->x = x;
    point->y = y;
}

int draw_square(t_window window, t_2D_point origin, int lenght, int color)
{
    t_2D_point right_up;
    t_2D_point right_down;
    t_2D_point left_down;

    set_point(&right_up, origin.x + lenght, origin.y);
    set_point(&right_down, origin.x + lenght, origin.y + lenght);
    set_point(&left_down, origin.x, origin.y + lenght);

    draw_line(window, origin.x, origin.y, right_up.x, right_up.y, color);
    draw_line(window, right_up.x, right_up.y, right_down.x, right_down.y, color);
    draw_line(window, left_down.x, left_down.y, right_down.x, right_down.y, color);
    draw_line(window, origin.x, origin.y, left_down.x, left_down.y, color);
    return 0;
}

int draw_pixel(t_window window, t_2D_point pixel, int color)
{
    mlx_pixel_put(window.ptr, window.win, pixel.x, pixel.y, color);
    return 0;
}

int draw_circle_points(t_window window, int xc, int yc, int x, int y, int color)
{
    mlx_pixel_put(window.ptr, window.win, xc + x, yc + y, color);
    mlx_pixel_put(window.ptr, window.win, xc - x, yc + y, color);
    mlx_pixel_put(window.ptr, window.win, xc + x, yc - y, color);
    mlx_pixel_put(window.ptr, window.win, xc - x, yc - y, color);
    mlx_pixel_put(window.ptr, window.win, xc + y, yc + x, color);
    mlx_pixel_put(window.ptr, window.win, xc - y, yc + x, color);
    mlx_pixel_put(window.ptr, window.win, xc + y, yc - x, color);
    mlx_pixel_put(window.ptr, window.win, xc - y, yc - x, color);
    return 0;
}

int draw_circle(t_window window, t_2D_point center, int r, int color)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    draw_circle_points(window, center.x, center.y, x, y, color);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels

        x++;

        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        draw_circle_points(window, center.x, center.y, x, y, color);
        
    }
    return (0);
}

void ft_swap(float *a, float *b)
{
    float temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


void draw_line(t_window window, float x1,float y1,float x2,float y2,int c )
{
	const float dx = x2 - x1;
	const float dy = y2 - y1;

	if( dy == 0.0f && dx == 0.0f )
	{
		mlx_pixel_put(window.ptr, window.win , (int)x1 ,(int)y1,c );
	}
	else if( fabsf( dy ) > fabsf( dx ) )
	{
		if( dy < 0.0f )
		{
			ft_swap( &x1,&x2 );
			ft_swap( &y1,&y2 );
		}

		const float m = dx / dy;
		float y = y1;
		int lastIntY = 0;
		for( float x = x1; y < y2; y += 1.0f,x += m )
		{
			lastIntY = (int)y;
			mlx_pixel_put(window.ptr, window.win ,(int)x,lastIntY,c );
		}
		if( (int)y2  > lastIntY )
		{
            
			mlx_pixel_put(window.ptr, window.win ,(int)x2,(int)y2,c );
		}
	}
	else
	{
		if( dx < 0.0f )
		{
			ft_swap( &x1,&x2 );
			ft_swap( &y1,&y2 );
		}

		const float m = dy / dx;
		float x = x1;
		int lastIntX = 0;
		for( float y = y1; x < x2; x += 1.0f,y += m )
		{
			lastIntX = (int)x;
           
			mlx_pixel_put(window.ptr, window.win ,lastIntX,(int)y,c );
		}
		if( (int)x2  > lastIntX )
		{
           
			mlx_pixel_put(window.ptr, window.win ,(int)x2,(int)y2 ,c );
		}
	}
}
