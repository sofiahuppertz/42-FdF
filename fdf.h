#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include "./libs/gnl/get_next_line.h"


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


typedef struct s_node
{
	char *str;
	char **row;
	struct s_node *next;

} t_node;


void insert_node(t_node **head, t_node *new_node);
int list_traverse(t_node **head, int *column_numb);
char ***matrix_generate(t_node **head, int row_numb, int column_numb);
char ***parsing(int fd);
t_node *read_map(int fd, int *row_num);




#endif