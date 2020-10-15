#include "../includes/cub3d.h"

void data_init(t_main *main)
{
    main->map.ceiling_color = 0;
    main->map.floor_color = 0;
    main->map.res_x = 0;
    main->map.res_y = 0;
    main->map.tex_e = NULL;
    main->map.tex_n = NULL;
    main->map.tex_s = NULL;
    main->map.tex_w = NULL;
    main->map.tex_sp = NULL;
    main->map.start_x = 0;
    main->map.start_y = 0;
    main->map.start_direction = '\0';
    main->map.sprite_number = 0;
    main->map.height = 0;
    main->map.tex_x = 64;
    main->map.tex_y = 64;
    main->camera.rot_dir =0;
    main->camera.move_dir = 0;
    main->camera.plane.x = 0;
    main->camera.plane.y = FOV;
}

void init_textures(t_main *m)
{
    m->tex[0].img = XPM(&m->window.ptr, m->map.tex_n, &m->map.tex_x, &m->map.tex_y);
    m->tex[1].img = XPM(&m->window.ptr, m->map.tex_s, &m->map.tex_x, &m->map.tex_y);
    m->tex[2].img = XPM(&m->window.ptr, m->map.tex_e, &m->map.tex_x, &m->map.tex_y);
    m->tex[3].img = XPM(&m->window.ptr, m->map.tex_w, &m->map.tex_x, &m->map.tex_y);
    m->tex[4].img = XPM(&m->window.ptr, m->map.tex_sp, &m->map.tex_x, &m->map.tex_y);
    if(!m->tex[0].img || !m->tex[1].img ||!m->tex[2].img ||!m->tex[3].img ||!m->tex[4].img)
        error("Couldn't load textures");
    free_text_path(&m->map);
    m->tex[0].addr = mlx_get_data_addr(m->tex[0].img, &m->tex[0].bpp, m->tex[0].line_size, m->tex[0].endian);
    m->tex[1].addr = mlx_get_data_addr(m->tex[1].img, &m->tex[1].bpp, m->tex[1].line_size, m->tex[1].endian);
    m->tex[2].addr = mlx_get_data_addr(m->tex[2].img, &m->tex[2].bpp, m->tex[2].line_size, m->tex[2].endian);
    m->tex[3].addr = mlx_get_data_addr(m->tex[3].img, &m->tex[3].bpp, m->tex[3].line_size, m->tex[3].endian);
    m->tex[4].addr = mlx_get_data_addr(m->tex[4].img, &m->tex[4].bpp, m->tex[4].line_size, m->tex[4].endian);
}
