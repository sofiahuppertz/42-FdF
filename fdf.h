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
	char **row;
	struct s_map_rows *next;

} t_map_row;

typedef struct s_point
{
	int x;
	int y;
}	t_point;


t_map_row *create_node(char *data);
t_point *edge_projection(int x, int y, int z);
int	free_map_rows(t_map_row *head);
void insert_node(t_map_row **head, t_map_row *new_node);
t_point ***isometric_transformation(char ***matrix, int row_numb, int column_numb);
int list_traverse(t_map_row **head, int *column_numb);
char ***matrix_generate(t_map_row **head, int *row_numb);
char	***parsing(int fd, int *row_numb, int *column_numb);
t_map_row *read_map(int fd, int *row_num);




#endif