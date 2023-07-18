s#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>


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


typedef struct node_s
{
	char *str;
	int *row;
	struct node_s *next;

} node_t

#endif