#include "../includes/cub3d.h"



This need to be implemented :
- have to had a sprite structure (int x , int y, ...)
- integrate this fonction after all the checks 

// int		set_sprite(t_info *info)
// {
// 	int	x;
// 	int	y;
// 	int	i;

// 	y = 0;
// 	i = 0;
// 	if (!(info->sprite =\
// 			(t_sprite *)malloc(sizeof(t_sprite) * info->num_sprite)))
// 		return (exit_error(info));
// 	while (y < info->map_height)
// 	{
// 		x = 0;
// 		while (x < info->map_width)
// 		{
// 			if (info->map[y][x] == '2')
// 			{
// 				set_pos_sprite(info, i, x, y);
// 				i++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);

int elem_type(t_map_data *data, int x, int y)
{
    char elem ;
    
    elem  = data->pattern[y][x];

    if (elem  == 'X')
        return (1);
    else if (elem  == '1')
        return (2);
    else if (elem == '2' || elem  == '0')
        return (3);
    else if (elem  == 'N' || elem  == 'S' || elem  == 'E' || elem  == 'W')
    {
        if(data->start_x == 0 && data->start_y == 0)
        {
            data->start_x = x;
            data->start_y = y;
            data->start_direction = elem;
        }
        else if(data->start_x != x || data->start_y != y )
            error("Start position declared more than once");
        return (4);
    }
    return (0);
}

void get_map_height(t_map_data *data)
{
    int i;

    i = 0;
    while(data->pattern[i])
        i++;
    data->height = i;
}

void check_adjacent_elem(t_map_data *data,int x, int y)
{
    int i;
    int j;

    if(data->pattern[y][x] == '2')
        data->sprite_number++;
    i = x - 1;
    while(i <= x + 1)
    {
        j = y - 1;
        while(j <= y + 1)
        {
            if(data->pattern[j][i] == '\0' || data->pattern[j][i] == 'X')
                error("map isn't totaly surrounded by walls");
            j++;
        }
        i++;
    }
}

int map_check(t_map_data *data)
{
    int x;
    int y;

    y = 0;
    while(y < data->height)
    {
        x = 0;
        while(x < ((int)ft_strlen(data->pattern[y])))
        {
            if(!elem_type(data, x, y))
                error("Unrecognized objet in map");
            if((y == 0 || y == data->height - 1) && elem_type(data, x, y) > 2)
                error("Map isn't closed on top or bottom wall");
            if(elem_type(data, x, y) >= 3)
                check_adjacent_elem(data, x, y);
            x++;
        }
        y++;
    }
    return 0;
}
