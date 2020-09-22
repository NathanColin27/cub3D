#ifndef FT_CUB3D_H
#define FT_CUB3D_H
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "../minilibx-linux/mlx.h"
// #include <mlx.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

#define RED 16711680
#define GREEN 65280
#define BLUE 255

typedef struct s_map
{
    int width;
    int height;
    int start_x;
    int start_y;
    char **pattern;

} t_map;

typedef struct s_session
{
    void *session;
    void *window;
} t_session;

typedef struct s_map_data
{
    int res_x;
    int res_y;
    int floor_color;
    int height;
    int ceiling_color;
    char texture_north[50];
    char texture_south[50];
    char texture_east[50];
    char texture_west[50];
    char texture_sprite[50];
    char **pattern;
    char start_direction;
    int start_x;
    int start_y;
    int sprite_number;
} t_map_data;

typedef struct s_main
{
    t_map_data data;
    t_session  session;
    t_map      map;
}              t_main;

typedef struct s_2D_point
{
    int x;
    int y;
} t_2D_point;

typedef struct s_vec3d
{
    float x;
    float y;
    float z;
} t_vec3d;

typedef struct s_triangle
{
    t_vec3d p[3];
} t_triangle;

int draw_pixel(t_session data, t_2D_point pixel, int color);
void draw_line(t_session data, float x1, float y1, float x2, float y2, int c);
int draw_circle_points(t_session data, int xc, int yc, int x, int y, int color);
void set_point(t_2D_point *point, int x, int y);
int draw_circle(t_session data, t_2D_point center, int r, int color);
int color_map_1(t_session data, int w, int h);
int draw_square(t_session data, t_2D_point origin, int lenght, int color);
void delay(int number_of_seconds);
int rgb(int r, int g, int b);
int valid_extension(char *map_name);
void error(char *s);
int valid_args(int ac);
void data_init(t_map_data *map_data);
int parse_res(char *line, t_map_data *data);
int parse_texture(char *line, t_map_data *data);
int parse_map_data(char *line, t_map_data *data);
int parse_colors(char *line, t_map_data *data);
int valid_file(t_map_data *data);
int valid_descriptor(char a, char b);
int valid_color(t_map_data *data);
int valid_map_data(t_map_data *data);
int is_map_start(char *line);
int parse_map_pattern(char *line, t_map_data *data, int fd);
char *space_to_wall(char *line);
char	*ft_strjoin_delimiter(char const *s1, char const *s2, char del);
int elem_type(t_map_data *data, int x, int y);
void get_map_height(t_map_data *data);
int map_check(t_map_data *data);
void check_adjacent_elem(t_map_data *data,int x, int y);

#endif