#include "../fdf.h"

char	***parsing(int fd, int *row_numb, int *column_numb)
{
	char	***parsed;
	t_map_row	*temp_list;

	parsed = NULL;
	temp_list = read_map(fd, row_numb);
	t_map_row *ptr = temp_list;
	while (ptr != NULL)
	{
		ptr = ptr->next;
	}
	if (temp_list)
	{
		parsed = matrix_generate(&temp_list, row_numb, column_numb);
	}
	free_map_rows(temp_list);
	return (parsed);
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
			return (NULL);
		}
		insert_node(&start, new_node);
		*row_num = *row_num + 1;
		free(new_line);
	}
	return (start);
}

//For each row separate into columns, count columns...
//Make a matrix with the number dimensions(row*columns)
//and the data we temporarily stored in the linked list.
char	***matrix_generate(t_map_row **head, int *row_numb, int *column_numb)
{
	t_map_row	*current;
	char	***matrix;
	char space;
	int	row;
	int len;

	matrix = malloc(sizeof(char **) * (*row_numb) + 1);
	if (!matrix)
		return (NULL);
	current = *head;
	row = 0;
	space = 32;
	while (current != NULL )
	{
		matrix[row] = ft_split((const char *)current->str, space);
		if (!matrix[row])
		{
			free_str_matrix(matrix, *row_numb, *column_numb);
			return (NULL);
		}
		if (row == 0)
		{
			len = (int)str_array_length((const char **)matrix[0]);
			*column_numb = len;
		}
		current = current->next;
		row++;
	}
	matrix[row] = NULL;
	head = NULL;
	return (matrix);
}


//TODO: convert to int before doing isonometric projection.