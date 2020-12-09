/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:39:23 by nathan            #+#    #+#             */
/*   Updated: 2020/12/09 10:48:56 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define ROT_SPEED 0.01
# define SPEED 0.1
# define FOV 0.66
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440
# define MIN_WIDTH 640
# define MIN_HEIGHT 480
# define ADDR mlx_get_data_addr
# define XPM mlx_xpm_file_to_image

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_ray
{
	t_pos	*dir;
	t_pos	*delta;
	t_pos	*side_dist;
	t_pos	*step;
	int		id;
	int		side;
	int		hit;
	int		map_x;
	int		map_y;
	int		wall_size;
	int		wall_start;
	int		wall_end;
	int		tex_x;
	int		tex_y;
	double	perp_wall_dist;
	double	wall_x;
	double	tex_step;
	double	tex_pos;
}				t_ray;

typedef struct	s_camera
{
	t_pos	*pos;
	t_pos	*dir;
	t_pos	*x_dir;
	t_pos	*plane;
	double	cam_x;
	int		move_dir_y;
	int		move_dir_x;
	int		rot_dir;
}				t_camera;

typedef struct	s_sprite
{
	double y;
	double x;
	double distance;
}				t_sprite;

typedef struct	s_sprite_data
{
	double	inv_det;
	double	pos_x;
	double	pos_y;
	int		h;
	int		w;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	double	transform_x;
	double	transform_y;
	int		screen_x;
}				t_sprite_data;

typedef	struct	s_img
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				line_size;
	int				endian;
	int				img_x;
	int				img_y;
}				t_img;

typedef struct	s_pxl
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}				t_pxl;

typedef struct	s_map
{
	int		res_x;
	int		res_y;
	int		floor_color;
	int		ceiling_color;
	int		height;
	char	start_direction;
	int		start_x;
	int		start_y;
	int		sprite_number;
	char	*tex_s;
	char	*tex_n;
	char	*tex_e;
	char	*tex_w;
	char	*tex_sp;
	char	**pattern;

}				t_map;

typedef struct	s_main
{
	t_map		*map;
	t_camera	*camera;
	t_img		tex[5];
	t_img		*screen;
	t_sprite	*sprites;
	t_ray		*ray;
	void		*mlx_ptr;
	void		*mlx_win;
	double		*z_buff;
	int			bmp;
}				t_main;

/*
**	Init
*/

int				data_init(t_main *m);
void			init_images(t_main *m, t_map *mp);
void			init_sprite(t_main *m);
int				init_buffer(t_main *m);

/*
** 	Parsing
*/

char			*space_to_wall(char *line);
int				valid_extension(t_main *m, char *map_name);
int				valid_args(t_main *m, int ac);
int				parse_res(char *line, t_map *map);
int				parse_texture(char *line, t_map *map);
void			parse_map_data(t_main *m, char *line, t_map *map);
void			parse_colors(t_main *m, char *line, t_map *map);
int				valid_file(t_main *m, t_map *map);
int				valid_descriptor(char a, char b);
int				valid_res(t_main *m, t_map *map);
int				valid_color(t_main *m, t_map *map);
int				valid_map_data(t_map *map);
int				is_map_start(t_main *m, char *line);
void			parse_map_pattern(t_main *m, char *line, t_map *map, int fd);
int				map_check(t_main *m);
int				elem_type(t_main *m, t_map *map, int x, int y);
void			get_map_height(t_map *map);
void			check_adjacent_elem(t_main *m, t_map *map, int x, int y);
void			set_start_pos(t_main *m);

/*
**	Raycasting
*/

int				raycasting(t_main *m);
void			dda(t_main *m, t_ray *r);
void			wall_size(t_main *m, t_ray *r, t_camera *c);
void			draw(t_main *m, t_ray *r);
int				move_cam_x(t_main *m);
int				move_cam_y(t_main *m);
void			cast_floor_ceiling(t_main *m);

/*
**	Sprites
*/

void			sprite(t_main *m, t_camera *c);
void			draw_sprite(t_main *m, int i);
void			sort_sprites(t_main *m);
void			sprite_distance(t_main *m, t_camera *c);

/*
**	Error
*/

void			error(t_main *m, char *s);

/*
**  Utils
*/

char			*ft_strjoin_delimiter(char *s1, char *s2, char del);
int				rgb(int r, int g, int b);
void			remove_spaces (char *s);
int				key_press(int keycode, t_main *m);
int				key_release(int keycode, t_main *m);
int				rotate_cam(t_main *m);
int				exit_pressed(t_main *m);
void			set_pos(t_pos *pos, double x, double y);
int				ft_skip(t_main *m, char *line, int i, int color);
int				ft_haschr(const char *s, int c);

/*
**	Textures
*/

void			calc_textures(t_main *m, t_ray *r, int x);
void			get_wall_color(t_main *m, t_ray *ray, int x);
void			get_wall_texture(t_camera *c, t_ray *ray);
void			pxl_to_img(t_main *m, int x, int y, int color);

/*
**	Free
*/

void			free_all(t_main *m);
void			free_text_path(t_map *map);
void			ft_free_img(t_img *img);
void			ft_free_ray(t_ray *r);
void			ft_free_sprites(t_sprite *s);
void			ft_free_map(t_map *m);
int				ft_free_array(char **array);

/*
**	Screenshot
*/

void			save_bmp(t_main *m);
void			write_header(t_main *m, unsigned char header[54], int fd);
void			write_bmp(t_main *m, int fd);
int				windows(t_main *m);
int				main_loop(t_main *m);
void			set_side_distance(t_camera *cam, t_ray *ray);
void			parse(t_main *m, int fd);

#endif
