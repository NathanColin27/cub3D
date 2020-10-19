#include "../includes/cub3d.h"

void data_init(t_main *main)
{
    main->bmp = 0;
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
    main->camera.rot_dir =0;
    main->camera.move_dir = 0;
    main->camera.plane.x = 0;
    main->camera.plane.y = FOV;
}

void init_textures(t_main *m)
{
    m->tex[0].img_ptr = XPM(&m->window.ptr, m->map.tex_n, &m->tex[0].img_x, &m->tex[0].img_y);
    m->tex[1].img_ptr = XPM(&m->window.ptr, m->map.tex_s, &m->tex[1].img_x, &m->tex[1].img_y);
    m->tex[2].img_ptr = XPM(&m->window.ptr, m->map.tex_e, &m->tex[2].img_x, &m->tex[2].img_y);
    m->tex[3].img_ptr = XPM(&m->window.ptr, m->map.tex_w, &m->tex[3].img_x, &m->tex[3].img_y);
    m->tex[4].img_ptr = XPM(&m->window.ptr, m->map.tex_sp, &m->tex[4].img_x, &m->tex[4].img_y);
    if(!m->tex[0].img_ptr || !m->tex[1].img_ptr ||!m->tex[2].img_ptr ||!m->tex[3].img_ptr ||!m->tex[4].img_ptr)
        error("Couldn't load textures");
    free_text_path(&m->map);
    m->tex[0].addr = (unsigned int*)mlx_get_data_addr(m->tex[0].img_ptr, &m->tex[0].bpp, &m->tex[0].line_size, &m->tex[0].endian);
    m->tex[1].addr = (unsigned int*)mlx_get_data_addr(m->tex[1].img_ptr, &m->tex[1].bpp, &m->tex[1].line_size, &m->tex[1].endian);
    m->tex[2].addr = (unsigned int*)mlx_get_data_addr(m->tex[2].img_ptr, &m->tex[2].bpp, &m->tex[2].line_size, &m->tex[2].endian);
    m->tex[3].addr = (unsigned int*)mlx_get_data_addr(m->tex[3].img_ptr, &m->tex[3].bpp, &m->tex[3].line_size, &m->tex[3].endian);
    m->tex[4].addr = (unsigned int*)mlx_get_data_addr(m->tex[4].img_ptr, &m->tex[4].bpp, &m->tex[4].line_size, &m->tex[4].endian);

    m->screen.img_ptr = mlx_new_image(&m->window.ptr,m->map.res_x, m->map.res_y);
    m->screen.addr = (unsigned int *)mlx_get_data_addr(m->screen.img_ptr, &m->screen.bpp, &m->screen.line_size, &m->screen.endian);
}

