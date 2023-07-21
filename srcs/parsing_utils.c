#include "fdf.h"

void insert_node(t_map_row **head, t_map_row *new_node)
{
    t_map_row *current;

    current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    
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