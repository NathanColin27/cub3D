/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by ncolin            #+#    #+#             */
/*   Updated: 2020/09/23 21:37:00 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"


int windows(t_map_data *data) 
{
    t_session       session;
    t_2D_point      start;
    t_2D_point      end;
    t_2D_point      origin;
    t_2D_point      center; 
    
    // void    *img;
    // char    *relative_path = "./textures/east.xpm";
    // int     img_width;
    // int     img_height;


    int width = data->res_x;
    int height =  data->res_y;
   
    set_point(&center, width/2, height/2);
    set_point(&start, 0, 0);
    set_point(&end, width, height);
    set_point(&origin, 170, 90);
    

    if ((session.session = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((session.window = mlx_new_window(session.session, width, height, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    int y = 10;
    // draw_line(session, start.x, start.y, end.x, end.y, rgb(255,255,0));
    // draw_square(session, center, 150, RED);
    // draw_circle(session, center, 100, GREEN);
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("res x = " ,ft_itoa(data->res_x)));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("res y = " ,ft_itoa(data->res_y)));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("texture_north = " ,data->texture_north));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("texture_south = " ,data->texture_south));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("texture_east = " ,data->texture_east));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("texture_west = " ,data->texture_west));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("texture_sprite = " ,data->texture_sprite));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("floor_color = " ,ft_itoa(data->floor_color)));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("ceiling_color = " ,ft_itoa(data->ceiling_color)));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("start_x = " ,ft_itoa(data->start_x)));
    y += 20;
    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("start_y = " ,ft_itoa(data->start_y)));
    y += 20;
    for (int i = 0; i < data->sprite_number; i++)
	{

	    mlx_string_put(session.session, session.window, 15, y, BLUE, ft_strjoin("sprite : x = " ,ft_itoa(data->sprites[i].x)));
        mlx_string_put(session.session, session.window, 170, y, BLUE, ft_strjoin(", y = " ,ft_itoa(data->sprites[i].y)));
        y += 20;
	}
    // img = mlx_xpm_file_to_image(session.session, relative_path, &img_width, &img_height);
    // mlx_put_image_to_window (session.session, session.window, img, img_width, img_height);
    int x;
    int offset_x = data->res_x/3;
    int offset_y = 20 ;
    y = 0;
    while(y < data->height)
    {
        x = 0;
        while(x < ((int)ft_strlen(data->pattern[y])))
        {
                
                if (data->pattern[y][x] == '1')
                {
                    for (int i = x*8; i < x*8 + 8; i++)
                        for (int j = y*8; j < y*8 + 8; j++)
                            mlx_pixel_put(session.session, session.window, offset_x + i, offset_y + j, GREEN);
                }
              
                
                x++;
        }
        y++;
    }

    mlx_loop(session.session);
    return (EXIT_SUCCESS);

}