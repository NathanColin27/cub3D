#include "includes/cub3D.h"



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

int main()
{
    t_session       data;
    t_2D_point      start;
    t_2D_point      end;
    t_2D_point      origin;
    t_2D_point      center; 
   
    void    *img;
    char    *relative_path = "./srcs/teapot.xpm";
    int     img_width;
    int     img_height;


    int width = 640;
    int height =  480;
   
    set_point(&center, width/2, height/2);
    set_point(&start, 0, 0);
    set_point(&end, width, height);
    set_point(&origin, 170, 90);
    

    if ((data.session = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.window = mlx_new_window(data.session, width, height, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    
    draw_line(data, start.x, start.y, end.x, end.y, rgb(255,255,0));
    draw_square(data, center, 150, RED);
    draw_circle(data, center, 100, GREEN);
    mlx_string_put(data.session, data.window, 15, 15, BLUE, "test");
    
    img = mlx_xpm_file_to_image(data.session, relative_path, &img_width, &img_height);
    mlx_put_image_to_window (data.session, data.window, img, img_width, img_height);


    mlx_loop(data.session);
    return (EXIT_SUCCESS);
}