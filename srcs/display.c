/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/13 16:18:37 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 


int windows(t_main *main)
{
    t_window window;

    if ((window.ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((window.win = mlx_new_window(window.ptr, main->map.res_x, main->map.res_y, "Cub3D")) == NULL)
        return (EXIT_FAILURE);
    main->window = window;
    info_and_map(main);
    mlx_hook(window.win, X_EVENT_KEY_PRESS, 0, key_press, &main);
    mlx_hook(window.win, X_EVENT_KEY_RELEASE, 0, key_release, &main);
    mlx_hook(window.win, X_EVENT_KEY_EXIT, 0, exit_pressed, &main);
    mlx_loop_hook(window.ptr, main_loop, main);
    mlx_loop(window.ptr);
    return (EXIT_SUCCESS);
}

int main_loop(t_main *main)
{
    raycasting(main);
    
    return 1;
}

int set_side_distance(t_camera *cam, t_ray *ray)
{
    if(ray->dir.x < 0)
    {
        ray->step.x = -1;
        ray->side_dist.x = ((int)cam->pos.x - cam->pos.x) * ray->delta.x;
    }
    else 
    {
        ray->step.x = 1;
        ray->side_dist.x = (cam->pos.x + 1.0 -(int)cam->pos.x) *ray->delta.x;
    }
    if(ray->dir.y < 0)
    {
        ray->step.y = -1;
        ray->side_dist.y = ((int)cam->pos.y - cam->pos.y) * ray->delta.y;
    }
    else 
    {
        ray->step.y = 1;
        ray->side_dist.y = (cam->pos.y + 1.0 -(int)cam->pos.y) *ray->delta.y;
    }
    return 1;
}

void check_side(t_ray *ray)
{
    if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta.x;
		ray->map_x += ray->step.x;
		if (ray->step.x == 1)
			ray->side = 0;
		else if (ray->step.x == -1)
			ray->side = 1;
	}
	else
	{
		ray->side_dist.y += ray->delta.y;
		ray->map_y += ray->step.y;
		if (ray->step.y == 1)
			ray->side = 2;
		else if (ray->step.y == -1)
			ray->side = 3;
	}
}






void  dda(t_main *main, t_ray *r)
{
    
    int size = 25;
    int offset_x = main->map.res_x / 2 - (size * ft_strlen(main->map.pattern[0]) / 2);
    int offset_y = main->map.res_y / 2 - (size * main->map.height / 2);
    while(r->hit == 0)
    {
        
        if (r->side_dist.x < r->side_dist.y)
		{
		    r->side_dist.x += r->delta.x;
			r->map_x += r->step.x;
			if (r->step.x == 1)
			    r->side = 0;
		    else if (r->step.x == -1)
			    r->side = 1;
		}
		else
		{
            
			r->side_dist.y += r->delta.y;
			r->map_y += r->step.y;
            if (r->step.y == 1)
			    r->side = 2;
		    else if (r->step.y == -1)
			    r->side = 3;
		}
        if (main->map.pattern[r->map_y][r->map_x] == '1')
        {   
            r->hit = 1;
        
        }
    }
}

void wall_size(t_main *main, t_ray *r, t_camera *c)
{
    delay(500);
    setvbuf(stdout, NULL, _IOLBF, 0);  
    printf("MAP_X -> %d\nMAP_Y -> %d\nPOS_X -> %f\nPOS_Y -> %f\nSTEP_X -> %f\nSTEP_X -> %f\nDIR_X -> %f\nDIR_Y -> %f\n",\
            r->map_x, r->map_y, c->pos.x, c->pos.y, r->step.x, r->step.y, r->dir.x, r->dir.y);
    printf("Wall hit in [%d][%d]     Dist = %f\n",r->map_x, r->map_y, r->perp_wall_dist);




    if(r->side == 0 || r->side == 1)
        r->perp_wall_dist =  (r->map_x - c->pos.x + (1 - r->step.x)/2) / r->dir.x; 
    else
        r->perp_wall_dist =  (r->map_y - c->pos.y + (1 - r->step.y)/2) / r->dir.y;
}



int raycasting(t_main *main)
{
    
    int i;
    t_camera *c;
    t_ray    *r;
    i = 0;
    c = &main->camera;
    r = &main->ray;
    int test = 0;
    test++;
    while (i < main->map.res_x)
    {
        c->cam_x = 1 - 2 * i/(double)(main->map.res_x);
        r->map_x = (int)c->pos.x;
        r->map_y = (int)c->pos.y;
        set_pos(&main->ray.dir, c->dir.x + c->plane.x * c->cam_x, c->dir.y + c->plane.y * c->cam_x);
        set_pos(&r->delta, fabs(1/ r->dir.x), fabs(1/ r->dir.y));
        r->hit = 0;
        r->id  = i;
        set_side_distance(c, r); 
        dda(main, r);
        wall_size(main, r, c);
        i++;
    }
    return 1;
}

void info_and_map(t_main *main)
{
    int x;
    int size = 25;
    int offset_x = main->map.res_x / 2 - (size * ft_strlen(main->map.pattern[0]) / 2);
    int offset_y = main->map.res_y / 2 - (size * main->map.height / 2);
    int y = 0;

    
    while (y < main->map.height)
    {
        x = 0;
        while (x < ((int)ft_strlen(main->map.pattern[y])))
        {
            if (main->map.pattern[y][x] == '1')
            {
                for (int i = x * size; i < x * size + size-1; i++)
                    for (int j = y * size; j < y * size + size-1; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, GREEN);
            }
            else if (main->map.pattern[y][x] == '2')
            {
                for (int i = x * size; i < x * size + size-1; i++)
                    for (int j = y * size; j < y * size + size-1; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, BLUE);
            }
            else if (main->map.pattern[y][x] == 'N' || main->map.pattern[y][x] == 'E' || main->map.pattern[y][x] == 'W' || main->map.pattern[y][x] == 'S')
            {
                for (int i = x * size; i < x * size + size-1; i++)
                    for (int j = y * size; j < y * size + size-1; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, RED);
            }
            else
            {
                for (int i = x * size; i < x * size + size -1; i++)
                    for (int j = y * size; j < y * size + size-1; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, WHITE);
            }

            x++;
        }
        y++;
    }
    
}