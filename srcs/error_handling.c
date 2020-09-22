#include "../includes/cub3d.h"

void error(char *message)
{
    ft_putstr_fd("Error\n", 1);
    ft_putstr_fd(message, 1);
    exit(0);
}

int valid_args(int ac)
{
    if (ac < 2)
    {
        error("Please provide a map");
        return (0);
    }
    else if (ac > 3)
    {
        error("Too much arguments");
        return (0);
    }
    return (1);
}

int valid_res(t_map_data *data)
{
    if (data->res_x <= 0 || data->res_y <= 0)
        error("Wrong resolution");
    if (data->res_x > 1920)
        data->res_x = 1920;
    if (data->res_y > 1080)
        data->res_y = 1080;
    return (1);
}

int valid_color(t_map_data *data)
{
    if (data->ceiling_color < 0)
        error("Wrong ceiling color");
    else if (data->floor_color < 0)
        error("Wrong floor color");
    return (1);
}

int valid_extension(char *map_name)
{
    char *dot = ft_strrchr(map_name, '.');
    if (dot && ft_strncmp(dot, ".cub", 5))
        error("Wrong file extension");
    if (open(map_name, O_RDONLY) == -1)
        error("Could'nt open file");
    return (1);
}

int valid_file(t_map_data *data)
{
    if ((open(data->texture_north, O_RDONLY)) == -1)
        error("Could not open North texture");
    else if (open(data->texture_south, O_RDONLY) == -1)
        error("Could not open South texture");
    else if (open(data->texture_east, O_RDONLY) == -1)
        error("Could not open East texture");
    else if (open(data->texture_west, O_RDONLY) == -1)
        error("Could not open West texture");
    else if (open(data->texture_sprite, O_RDONLY) == -1)
        error("Could not open Sprite texture");
    return (1);
}

int valid_map_data(t_map_data *data)
{
    return ((valid_color(data) && valid_file(data) && valid_res(data)));
}