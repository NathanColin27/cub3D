#ifndef FT_CUB3D_H
#define FT_CUB3D_H
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "../minilibx-linux/mlx.h"
//#include <mlx.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

#define RED 16711680
#define GREEN 65280
#define BLUE 255
#define WHITE 16777215

typedef struct  s_movement
{
    int move_x;
    int move_y;
    int rotate_x;
    int rotate_y;
}               t_movement;

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
}              t_main;


void draw_line(t_window data, float x1, float y1, float x2, float y2, int c);
int draw_circle_points(t_window data, int xc, int yc, int x, int y, int color);
int color_map_1(t_window data, int w, int h);
void delay(int number_of_seconds);
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
int key_press(int keycode, t_window *data);
int key_release(int keycode, t_window *data);
int main_loop(t_main *main);

#endif