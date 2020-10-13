/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:14:59 by nathan            #+#    #+#             */
/*   Updated: 2020/10/13 15:54:26 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_pos(t_pos *pos,double x,double y)
{
    pos->x = x;
    pos->y = y;
}

void ft_swap(float *a, float *b)
{
    float temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void draw_line(t_window data, float x1,float y1,float x2,float y2,int c )
{
	const float dx = x2 - x1;
	const float dy = y2 - y1;

	if( dy == 0.0f && dx == 0.0f )
	{
		mlx_pixel_put(data.ptr, data.win , (int)x1 ,(int)y1,c );
	}
	else if( fabs( dy ) > fabs( dx ) )
	{
		if( dy < 0.0f )
		{
			ft_swap( &x1,&x2 );
			ft_swap( &y1,&y2 );
		}

		const float m = dx / dy;
		float y = y1;
		int lastIntY;
		for( float x = x1; y < y2; y += 1.0f,x += m )
		{
			lastIntY = (int)y;
          
			mlx_pixel_put(data.ptr, data.win ,(int)x,lastIntY,c );
		}
		if( (int)y2  > lastIntY )
		{
   
			mlx_pixel_put(data.ptr, data.win ,(int)x2,(int)y2,c );
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
		int lastIntX;
		for( float y = y1; x < x2; x += 1.0f,y += m )
		{
			lastIntX = (int)x;
          
			mlx_pixel_put(data.ptr, data.win ,lastIntX,(int)y,c );
		}
		if( (int)x2  > lastIntX )
		{
         
			mlx_pixel_put(data.ptr, data.win ,(int)x2,(int)y2 ,c );
		}
	}
}