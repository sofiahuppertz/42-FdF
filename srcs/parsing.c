#include "../fdf.h"

char	***parsing(int fd, int *row_numb, int *column_numb)
{
	char	***parsed;
	t_map_row	**temp_list;

	*temp_list = read_map(fd, row_numb);
	if (*temp_list)
	{
		list_traverse(temp_list, column_numb);
		parsed = matrix_generate(temp_list, row_numb);
		return (parsed);
	}
	return (NULL);

}

//Read file, store each line, count rows thereby...
// Ask Akadil something at the end, about return (NULL)
t_map_row	*read_map(int fd, int *row_num)
{
	char	*new_line;
	t_map_row	*start;
	t_map_row *new_node;

	start = NULL;
	while ((new_line = get_next_line(fd)) != NULL)
	{
		new_node = create_node(ft_strdup(new_line));
		if (!new_node)
		{
			free_map_rows(start);
		}
		insert_node(&start, new_node);
		*row_num = *row_num + 1;
	}
	free(new_line);
	return (start);
}

//For each row separate into columns, count columns...
int	list_traverse(t_map_row **head, int *column_numb)
{
	t_map_row	*ptr;
	char space;

	ptr = *head;
	space = 32;
	while (ptr != NULL)
	{
		ptr->row = ft_split(ptr->str, space);
		if (!ptr->row)
		{
			free_map_rows(*head);
			return (1);
		}
		ptr = ptr->next;
		column_numb = column_numb + 1;
	}
	return (0);
}

//Make a matrix with the number dimensions(row*columns)
//and the data we temporarily stored in the linked list.
char	***matrix_generate(t_map_row **head, int *row_numb)
{
	char	***matrix;
	char ***matrix_start;
	t_map_row	*ptr;
	int size;

	size = *row_numb;
	matrix = malloc(sizeof(char **) * size);
	if (!matrix)
		return (NULL);
	ptr = *head;
	matrix_start = matrix;
	while (ptr != NULL)
	{
		*matrix = ptr->row;
		matrix++;
		ptr = ptr->next;
	}
	*matrix = NULL;
	return (matrix_start);
}


//TODO: convert to int before oing isonometric projection.