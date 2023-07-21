#include "../fdf.h"

void insert_node(t_map_row **head, t_map_row *new_node)
{
    t_map_row *current;

	if (head == NULL)
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
	t_map_row	*new_node;
	new_node = malloc(sizeof(t_map_row));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->str = data;
	new_node->next = NULL;
	return(new_node);
}

int	free_map_rows(t_map_row *head)
{
	t_map_row	*current;
	char	*temp;
    char **row_temp;

	while (head != NULL)
	{
		current = head;
		temp = current->str;
        row_temp = current->row;
		head = head->next;
		free(temp);
		free(row_temp);
		free(current);
	}
	return (0);
}