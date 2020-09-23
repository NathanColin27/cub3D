#include "../includes/cub3d.h"

void data_init(t_map_data *map_data)
{
    map_data->ceiling_color = 0;
    map_data->floor_color = 0;
    map_data->res_x = 0;
    map_data->res_y = 0;
    map_data->texture_east = NULL;
    map_data->texture_north = NULL;
    map_data->texture_south = NULL;
    map_data->texture_west = NULL;
    map_data->texture_sprite = NULL;
    map_data->start_x = 0;
    map_data->start_y = 0;
    map_data->start_direction = '\0';
    map_data->sprite_number = 0;
    map_data->height = 0;
}
