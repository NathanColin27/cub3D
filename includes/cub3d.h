#ifndef FT_CUB3D_H
#define FT_CUB3D_H
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "../minilibx-linux/mlx.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17
#define ROT_SPEED 0.05
#define SPEED 0.1
#define FOV 0.66
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_ESC 53
#define RED 16711680
#define GREEN 65280
#define BLUE 255
#define WHITE 16777215
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080
#define MIN_WIDTH 640
#define MIN_HEIGHT 480
#define XPM mlx_xpm_file_to_image

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_ray
{
    int id;
    int side;
    int hit;
    int map_x;
    int map_y;
    int wall_size;
    int wall_start;
    int wall_end;
    int tex_x;
    int tex_y;
    double perp_wall_dist;
    double wall_x;
    double tex_step;
    double tex_pos;
    t_pos dir;
    t_pos delta;
    t_pos side_dist;
    t_pos step;
}           t_ray;

typedef struct	s_camera
{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
    double  cam_x;
    int     move_dir;
    int     rot_dir;

}				t_camera;

typedef struct  s_window
{
    void *ptr;
    void *win;
}               t_window;

typedef struct s_sprite
{
    int x;
    int y;
}              t_sprite;

typedef struct s_img
{
    void *img_ptr;
    unsigned int *addr;
    int bpp;
    int line_size;
    int endian;
    int img_x;
    int img_y;
}               t_img;

typedef struct s_pxl
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
}               t_pxl;


typedef struct s_map
{
    int res_x;
    int res_y;
    int floor_color;
    int height;
    int ceiling_color;
    char *tex_s;
    char *tex_n;
    char *tex_e;
    char *tex_w;
    char *tex_sp;
    int tex_x;
    int tex_y;
    char **pattern;
    char start_direction;
    int start_x;
    int start_y;
    int sprite_number;
}               t_map;

typedef struct s_main
{
    t_map       map;
    t_window    window;
    t_sprite    *sprites;
    t_camera    camera;
    t_ray       ray;
    t_img       tex[5];
    t_img       screen;
    double      *z_buff;
    int         bmp;
    int         **buff; 
}              t_main;

int rgb(int r, int g, int b);
int valid_extension(char *map_name);
void error(char *s);
int valid_args(int ac);
void data_init(t_main *main);
int parse_res(char *line, t_map *map);
int parse_texture(char *line, t_map *map);
int parse_map_data(char *line, t_map *map);
int parse_colors(char *line, t_map *map);
int valid_file(t_map *map);
int valid_descriptor(char a, char b);
int valid_color(t_map *map);
int valid_map_data(t_map *map);
int is_map_start(char *line);
int parse_map_pattern(char *line, t_map *map, int fd);
char *space_to_wall(char *line);
char *ft_strjoin_delimiter(char const *s1, char const *s2, char del);
int elem_type(t_map *map, int x, int y);
void get_map_height(t_map *map);
int map_check(t_main *main);
void check_adjacent_elem(t_map *map,int x, int y);
int set_sprite(t_main *main);
int windows(t_main *main);
void delay(int number_of_seconds);
void remove_spaces (char *s);
void info_and_map(t_main *main);
int key_press(int keycode, t_main *main);
int key_release(int keycode, t_main *main);
int main_loop(t_main *main);
int exit_pressed(t_window *window);
int set_start_pos(t_main *main);
void set_pos(t_pos *pos, double x, double y);
int raycasting(t_main *main);
void  dda(t_main *main, t_ray *r);
void draw_line(t_window data, float x1,float y1,float x2,float y2,int c );
void wall_size(t_main *main, t_ray *r, t_camera *c);
void draw(t_main *main, t_ray *r);
int move_cam(t_main *main);
int set_side_distance(t_camera *cam, t_ray *ray);
int rotate_cam(t_main *main);
void init_textures(t_main *m);
void free_text_path(t_map *map);
void pxl_to_img(t_main *main, int x, int y, int color);
void parse(t_main *main, int fd);
void save_bmp(t_main *main);
void write_header(t_main *m, unsigned char header[54], int fd);
void write_bmp(t_main *m, int fd);
void calc_textures(t_main *m, t_ray *r, t_camera *c, int x);
void	get_wall_color(t_main *m, t_ray *ray, int x);
void	get_wall_texture(t_camera *c, t_ray *ray);
void	cast_floor_ceiling(t_main *m);

#endif