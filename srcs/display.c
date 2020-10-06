/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/10/06 16:43:40 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

#define KEY_w 119
#define KEY_a 97
#define KEY_s 115
#define KEY_d 100
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_ESC 65307

int key_press(int keycode, t_window *window)
{
    if (keycode == KEY_w)
        write(1, "up", 3);
    if (keycode == KEY_a)
        write(1, "left", 4);
    if (keycode == KEY_s)
        write(1, "down", 4);
    if (keycode == KEY_d)
        write(1, "right", 5);
    if (keycode == KEY_UP)
        write(1, "UP", 2);
    if (keycode == KEY_DOWN)
        write(1, "DOWN", 4);
    if (keycode == KEY_RIGHT)
        write(1, "RIGHT", 5);
    if (keycode == KEY_LEFT)
        write(1, "LEFT", 4);
    if (keycode == KEY_ESC)
        write(1, "ESC", 3);
    return 1;
}

int key_release(int keycode, t_window *window)
{
    return 1;
}

int exit_pressed(t_window *window)
{
    write(1, "bye", 5);
    exit(0);
    return (1);
}

int windows(t_map_data *data)
{
    t_window window;

    if ((window.ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((window.win = mlx_new_window(window.ptr, data->res_x, data->res_y, "Cub3D")) == NULL)
        return (EXIT_FAILURE);
    info_and_map(data, window);

    mlx_hook(window.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &window);
    mlx_hook(window.win, X_EVENT_KEY_RELEASE, 0, key_release, &window);
    //mlx_hook(window.win, X_EVENT_KEY_EXIT, 0, exit_pressed, &window);
    //mlx_loop_hook(window.ptr, main_loop, data);
    mlx_loop(window.ptr);
    return (EXIT_SUCCESS);
}

int main_loop(t_map_data *data)
{
    printf("test");
    raycasting(data);
    return 1;
}

int raycasting(t_map_data *data)
{
}

void info_and_map(t_map_data *data, t_window window)
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
    int offset_x = data->res_x / 2 - (size * ft_strlen(data->pattern[0]) / 2);
    int offset_y = data->res_y / 2 - (size * data->height / 2);
    int y = 0;

    while (y < data->height)
    {
        x = 0;
        while (x < ((int)ft_strlen(data->pattern[y])))
        {

            if (data->pattern[y][x] == '1')
            {
                for (int i = x * size; i < x * size + size; i++)
                    for (int j = y * size; j < y * size + size; j++)
                        mlx_pixel_put(window.ptr, window.win, offset_x + i, offset_y + j, GREEN);
            }
            else if (data->pattern[y][x] == '2')
            {
                for (int i = x * size; i < x * size + size; i++)
                    for (int j = y * size; j < y * size + size; j++)
                        mlx_pixel_put(window.ptr, window.win, offset_x + i, offset_y + j, BLUE);
            }
            else if (data->pattern[y][x] == 'N' || data->pattern[y][x] == 'E' || data->pattern[y][x] == 'W' || data->pattern[y][x] == 'S')
            {
                for (int i = x * size; i < x * size + size; i++)
                    for (int j = y * size; j < y * size + size; j++)
                        mlx_pixel_put(window.ptr, window.win, offset_x + i, offset_y + j, RED);
            }

            x++;
        }
        y++;
    }
}