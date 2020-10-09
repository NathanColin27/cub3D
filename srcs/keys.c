/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:38:13 by nathan            #+#    #+#             */
/*   Updated: 2020/10/09 11:52:03 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_press(int keycode, t_main *main)
{
    if (keycode == KEY_w || keycode == KEY_UP)
        main->move.up = 1;
    else if (keycode == KEY_s || keycode == KEY_DOWN)
        main->move.down = 1;
    if (keycode == KEY_a || keycode == KEY_LEFT)
        main->move.left = 1;
    else if (keycode == KEY_d || keycode == KEY_RIGHT)
        main->move.right = 1;
    return (0);
}

int key_release(int keycode, t_main *main)
{
    if (keycode == KEY_w || keycode == KEY_UP)
        main->move.up = 0;
    else if (keycode == KEY_s || keycode == KEY_DOWN)
        main->move.down = 0;
    else if (keycode == KEY_a || keycode == KEY_LEFT)
        main->move.left = 0;
    else if (keycode == KEY_d || keycode == KEY_RIGHT)
        main->move.right = 0;
    else if (keycode == KEY_ESC)
        exit_pressed(&main->window);
    return 1;
}

int exit_pressed(t_window *window)
{
    mlx_destroy_window(window->ptr, window->win);
    exit(0);
    return (1);
}