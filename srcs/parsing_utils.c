#include "../fdf.h"

void insert_node(t_map_row **head, t_map_row *new_node)
{
    t_map_row *current;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
    	while (current->next != NULL)
    	{
    	    current = current->next;
    	}
    	current->next = new_node;
	} 
}

t_map_row *create_node(char *data)
{
	//ft_printf("data to insert in the node: %s\n", data);
	t_map_row	*new_node;
	new_node = malloc(sizeof(t_map_row));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->str = data;
	//ft_printf("data in the node: %s\n", new_node->str);
	new_node->next = NULL;
	return(new_node);
}

void	free_map_rows(t_map_row *head)
{
	t_map_row	*current;
	char	*data;

	while (head != NULL)
	{
		current = head;
		data = current->str;
		head = head->next;
		free(data);
		free(current);
	}
}

void free_str_matrix(char ***matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);
}
