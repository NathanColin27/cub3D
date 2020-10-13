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


#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17


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
    double distance;
    double perp_wall_dist;
    t_pos dir;
    t_pos pos;
    t_pos delta;
    t_pos side_dist;
    t_pos step;
}           t_ray;

typedef struct  s_move
{
    int up;
    int down;
    int left;
    int right;
}               t_move;



typedef struct	s_camera
{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
    double cam_x;
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
} t_sprite;

typedef struct s_map
{
    int res_x;
    int res_y;
    int floor_color;
    int height;
    int ceiling_color;
    char *texture_south;
    char *texture_north;
    char *texture_east;
    char *texture_west;
    char *texture_sprite;
    char **pattern;
    char start_direction;
    int start_x;
    int start_y;
    int sprite_number;
} t_map;

typedef struct s_main
{
    t_map       map;
    t_window    window;
    t_sprite    *sprites;
    t_move      move;
    t_camera    camera;
    t_ray       ray;
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

#endif