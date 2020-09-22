#include "../includes/cub3d.h"

int is_map_start(char *line)
{
    if (line[0] == '1' || line[0] == ' ')
        return (1);
    return (0);
}

int parse_res(char *line, t_map_data *data)
{
    int i;

    i = 0;
    if (line[i] != 'R')
        return (0);
    while (!ft_isdigit(line[i]))
        i++;
    data->res_x = ft_atoi(&line[i]);
    while (!ft_isspace(line[i]))
        i++;
    data->res_y = ft_atoi(&line[i]);
    return (1);
}

int valid_descriptor(char a, char b)
{
    if (a == 'N' && b == 'O')
        return (1);
    else if (a == 'S' && b == 'O')
        return (1);
    else if (a == 'W' && b == 'E')
        return (1);
    else if (a == 'E' && b == 'A')
        return (1);
    else if (a == 'S' && b == ' ')
        return (1);
    else
        return (0);
}

int parse_texture(char *line, t_map_data *data)
{
    int i;

    i = 2;
    while (ft_isspace(line[i]))
        i++;
    if (line[0] == 'N' && line[1] == 'O')
        ft_strcpy(data->texture_north, &line[i]);
    else if (line[0] == 'S' && line[1] == 'O')
        ft_strcpy(data->texture_south, &line[i]);
    else if (line[0] == 'W' && line[1] == 'E')
        ft_strcpy(data->texture_west, &line[i]);
    else if (line[0] == 'E' && line[1] == 'A')
        ft_strcpy(data->texture_east, &line[i]);
    else if (line[0] == 'S' && line[1] == ' ')
        ft_strcpy(data->texture_sprite, &line[i]);
    return (1);
}

int parse_colors(char *line, t_map_data *data)
{
    int i;
    int r;
    int g;
    int b;

    i = 2;
    while (ft_isspace(line[i]))
        i++;
    r = ft_atoi(&line[i]);
    i++;
    while (!ft_isspace(line[i]))
        i++;
    g = ft_atoi(&line[i]);
    i++;
    while (!ft_isspace(line[i]))
        i++;
    b = ft_atoi(&line[i]);
    if (line[0] == 'F')
        data->floor_color = rgb(r, g, b);
    else if (line[0] == 'C')
        data->ceiling_color = rgb(r, g, b);
    return (1);
}

int rgb(int r, int g, int b)
{
    return (65536 * r + 256 * g + b);
}

int parse_map_data(char *line, t_map_data *data)
{
    if (line[0] == 'R')
        return (parse_res(line, data));
    else if (valid_descriptor(line[0], line[1]))
    {
        return (parse_texture(line, data));
    }
    else if (line[0] == 'C' || line[0] == 'F')
        return (parse_colors(line, data));
    else
        return (1);
}