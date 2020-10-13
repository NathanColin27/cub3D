#include "../includes/cub3d.h"

void data_init(t_main *main)
{
    main->map.ceiling_color = 0;
    main->map.floor_color = 0;
    main->map.res_x = 0;
    main->map.res_y = 0;
    main->map.texture_east = NULL;
    main->map.texture_north = NULL;
    main->map.texture_south = NULL;
    main->map.texture_west = NULL;
    main->map.texture_sprite = NULL;
    main->map.start_x = 0;
    main->map.start_y = 0;
    main->map.start_direction = '\0';
    main->map.sprite_number = 0;
    main->map.height = 0;

    main->move.up = 0;
    main->move.down = 0;
    main->move.left = 0;
    main->move.right= 0;

    main->camera.plane.x = 0;
    main->camera.plane.y = FOV;
}
