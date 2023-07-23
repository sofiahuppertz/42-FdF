#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>
#include "libs/libft/libft.h"
#include "libs/libft/get_next_line.h"
#include "libs/libft/ft_printf.h"
#include "libs/mlx/mlx.h"

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}			t_data;


typedef struct s_map_rows
{
	char *str;
	struct s_map_rows *next;

} t_map_row;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_layout
{
	int min_x;
	int min_y;
	int max_x;
	int max_y;
	int height;
	int width;
	int offset_x;
	int offset_y;
	double scale;
} t_layout;

t_map_row *create_node(char *data);
void	free_map_rows(t_map_row *head);
void    fit_grid_to_window(t_point ***grid, int height, int width);
void free_point_matrix(t_point ***matrix);
void free_str_matrix(char ***matrix, int rows, int columns);
void insert_node(t_map_row **head, t_map_row *new_node);
t_point ***isometric_transformation(char ***matrix, int row_numb, int column_numb);
char ***matrix_generate(t_map_row **head, int *row_numb, int *column_numb);
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	***parsing(int fd, int *row_numb, int *column_numb);
t_point *projected_point(int x, int y, int z);
t_map_row *read_map(int fd, int *row_num);
void set_offset(t_layout *layout);
void    set_scale(t_layout *layout);
void    set_extent(t_layout *layout, t_point ***grid, int height, int width);
//int    rendering(t_point ***matrix, int rows, int columns);
//void  set_values(t_data *init);




#endif