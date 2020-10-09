/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/09 22:09:23 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <time.h> 

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
    mlx_hook(window.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &main);
    mlx_hook(window.win, X_EVENT_KEY_RELEASE, 1L<<1, key_release, &main);
    mlx_hook(window.win, X_EVENT_KEY_EXIT, 1L<<15, exit_pressed, &main);
    mlx_loop_hook(window.ptr, main_loop, &main);
    mlx_loop(window.ptr);
    return (EXIT_SUCCESS);
}

int main_loop(t_main *main)
{
    int update = 1;
    delay(100);
    if (update)
    {
        raycasting(main);
        // screen_update();
        // window_update();
        update = 0;
    }
    if(main->move.up == 1)
        update = 1;
    if(main->move.down == 1)
    {
        update = 1;
    }
    
    if(main->move.left == 1 || main->move.right == 1)
    {
        write(1, "rotating", 9);
    }
  
    update = 0;
    return 1;
}

int set_side_distance(t_camera *cam, t_ray *ray)
{
    if(ray->dir.x < 0)
    {
        ray->step.x = -1;
        ray->side.x = ((int)cam->pos.x - cam->pos.x) * ray->delta.x;
    }
    else 
    {
        ray->step.x = 1;
        ray->side.x = (cam->pos.x + 1.0 -(int)cam->pos.x) *ray->delta.x;
    }
    if(ray->dir.y < 0)
    {
        ray->step.y = -1;
        ray->side.y = ((int)cam->pos.y - cam->pos.y) * ray->delta.y;
    }
    else 
    {
        ray->step.y = 1;
        ray->side.y = (cam->pos.y + 1.0 -(int)cam->pos.y) *ray->delta.y;
    }
    return 1;
}


int dda(t_main *main, t_ray *ray)
{
}

int set_ray(t_main *main)
{
    t_ray *r;

    r = &main->ray;
    set_pos(&r->delta, abs(1/ r->dir.x), abs(1/ r->dir.y));
    set_side_distance(&main->camera, &main->ray);
    
    return 1;
}

int raycasting(t_main *main)
{
    t_camera *c;
    double cam_x;
    int i;
    
    i = 0;
    c = &main->camera;
    while (i< main->map.res_x)
    {
        cam_x = 1 - 2 * i/(double)(main->map.res_x);
        set_pos(&main->ray.dir, c->dir.x + c->plane.x * cam_x, c->dir.y + c->plane.y * cam_x);
        set_ray(main);
        i++;
    }
    write(1, "DONE", 5);
    
}

void info_and_map(t_main *main)
{

    // int y = 10;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("res x = ", ft_itoa(data->res_x)));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("res y = ", ft_itoa(data->res_y)));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("texture_north = ", data->texture_north));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("texture_south = ", data->texture_south));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("texture_east = ", data->texture_east));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("texture_west = ", data->texture_west));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("texture_sprite = ", data->texture_sprite));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("floor_color = ", ft_itoa(data->floor_color)));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("ceiling_color = ", ft_itoa(data->ceiling_color)));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("start_x = ", ft_itoa(data->start_x)));
    // y += 20;
    // mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("start_y = ", ft_itoa(data->start_y)));
    // y += 20;
    // for (int i = 0; i < data->sprite_number; i++)
    // {
    //     mlx_string_put(window.ptr, window.win, 15, y, BLUE, ft_strjoin("sprite : x = ", ft_itoa(data->sprites[i].x)));
    //     mlx_string_put(window.ptr, window.win, 170, y, BLUE, ft_strjoin(", y = ", ft_itoa(data->sprites[i].y)));
    //     y += 20;
    // }

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
                for (int i = x * size; i < x * size + size; i++)
                    for (int j = y * size; j < y * size + size; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, GREEN);
            }
            else if (main->map.pattern[y][x] == '2')
            {
                for (int i = x * size; i < x * size + size; i++)
                    for (int j = y * size; j < y * size + size; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, BLUE);
            }
            else if (main->map.pattern[y][x] == 'N' || main->map.pattern[y][x] == 'E' || main->map.pattern[y][x] == 'W' || main->map.pattern[y][x] == 'S')
            {
                for (int i = x * size; i < x * size + size; i++)
                    for (int j = y * size; j < y * size + size; j++)
                        mlx_pixel_put(main->window.ptr, main->window.win, offset_x + i, offset_y + j, RED);
            }

            x++;
        }
        y++;
    }
}