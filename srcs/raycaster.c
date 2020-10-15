/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:40:31 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/15 17:12:53 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int raycasting(t_main *main)
{
    
    int i;
    t_camera *c;
    t_ray    *r;
    
    i = 0;
    c = &main->camera;
    r = &main->ray;
    while (i++ < main->map.res_x)
    {
        
        c->cam_x = 2 * i / (double)(main->map.res_x) - 1;
        set_pos(&r->dir, c->dir.x + c->plane.x * c->cam_x, c->dir.y + c->plane.y * c->cam_x);
        set_pos(&r->delta, fabs(1/ r->dir.x), fabs(1/ r->dir.y));
        r->map_x = (int)c->pos.x;
        r->map_y = (int)c->pos.y;
        r->hit = 0;
        r->id  = i;
        set_side_distance(c, r); 
        dda(main, r);
        wall_size(main, r, c);
        main->z_buff[i] = r->perp_wall_dist;
        draw(main, &main->ray);
    }
    return 1;
}


void draw(t_main *main, t_ray *r)
{

    clock_t tic = clock();
    // int color;
    // int x = main->map.res_x - r->id;
    // int i = 0;
    // if(r->side == 0)
    //     color = 0;
    // else if(r->side == 1)
    //     color = 16711935;
    // else if(r->side == 2)
    //     color = RED;
    // else if(r->side == 3)
    //     color = 51300;
    // while(i++ < r->wall_start)
    //     mlx_pixel_put(main->window.ptr, main->window.win, x, i, main->map.ceiling_color);
    // while(i++ < r->wall_start + r->wall_size)
    //     mlx_pixel_put(main->window.ptr, main->window.win, x, i, color);
    // while(i++ < main->map.res_y)
    //     mlx_pixel_put(main->window.ptr, main->window.win, x, i, main->map.floor_color);
    clock_t toc = clock();
        printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    

    //draw_line(main->window, main->map.res_x - r->id, r->wall_start + r->wall_size, main->map.res_x - r->id, r->wall_start, color);
    // draw_line(main->window, main->map.res_x - r->id, 0 , main->map.res_x - r->id, r->wall_start, BLUE);
    //draw_line(main->window, main->map.res_x - r->id, r->wall_start + r->wall_size , main->map.res_x - r->id, main->map.res_x -1, GREEN);
}


int set_side_distance(t_camera *cam, t_ray *ray)
{
    if(ray->dir.x < 0)
    {
        ray->step.x = -1;
        ray->side_dist.x = (cam->pos.x - ray->map_x) * ray->delta.x;
    }
    else 
    {
        ray->step.x = 1;
        ray->side_dist.x = (ray->map_x + 1 - cam->pos.x) *ray->delta.x;
    }
    if(ray->dir.y < 0)
    {
        ray->step.y = -1;
        ray->side_dist.y = (cam->pos.y - ray->map_y) * ray->delta.y;
    }
    else 
    {
        ray->step.y = 1;
        ray->side_dist.y = (ray->map_y + 1 - cam->pos.y) * ray->delta.y;
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
    if(r->side == 0 || r->side == 1)
        r->perp_wall_dist =  ((double)r->map_x - c->pos.x + (1 - r->step.x)/2) / r->dir.x; 
    else
        r->perp_wall_dist =  ((double)r->map_y - c->pos.y + (1 - r->step.y)/2) / r->dir.y;
    if(r->perp_wall_dist <= 0.5)
        r->perp_wall_dist = 0.5;
    r->wall_size = (int)(main->map.res_y / r->perp_wall_dist);
    r->wall_start = (-r->wall_size / 2 + (main->map.res_y / 2));
    if (r->wall_start <= 0)
        r->wall_start = 0;
    r->wall_end = (r->wall_size / 2 +  (main->map.res_y / 2));
    if (r->wall_end <= main->map.res_y)
        r->wall_end = main->map.res_y - 1;
}