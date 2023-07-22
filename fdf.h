#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include "libs/libft/libft.h"
#include "libs/libft/get_next_line.h"
#include "libs/libft/ft_printf.h"
#include "libs/minilibx-linux/mlx.h"

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


t_map_row *create_node(char *data);
void	free_map_rows(t_map_row *head);
void free_point_matrix(t_point ***matrix);
void free_str_matrix(char ***matrix, int rows, int columns);
void insert_node(t_map_row **head, t_map_row *new_node);
t_point ***isometric_transformation(char ***matrix, int row_numb, int column_numb);
char ***matrix_generate(t_map_row **head, int *row_numb, int *column_numb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	***parsing(int fd, int *row_numb, int *column_numb);
t_point *projected_point(int x, int y, int z);
t_map_row *read_map(int fd, int *row_num);
int    wireframe_rendering(t_point ***matrix, int rows, int columns);




#endif