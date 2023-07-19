#include "fdf.h"

void insert_node(t_node **head, t_node *new_node)
{
    t_node *current;

    current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    
}

int	free_list(t_node *head)
{
	t_node	*current;
	char	*temp;
    char **row_temp;

	while (head != NULL)
	{
		current = head;
		temp = current->str;
        row_temp = current->row;
		head = head->next;
		free(temp);
		free(current);
	}
	return (0);
}