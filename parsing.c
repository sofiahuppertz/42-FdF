#include "fdf.h"
#include "./gnl/get_next_line.h"

//Return a linked list with each row in a node, string format. Store the number of rows.
node_t **read_map(int fd, node_t **head, int *row_num)
{
    char *line;
    
    while(1)
    {
        line = get_next_line(fd);
        if (line)
        {
            node_t *temp;
            temp = malloc(sizeof(t_node));
            if (!temp)
                return (NULL);
            temp->str = line;
            lst_add_back(head, temp);
            row_num += 1;
        }
        else
            break;
    }
    return (head);
}


//Take linked list.
//Traverse linked list and for each node "splint" the str to int *row. 
//Reminder: we will need to store the info for the number of columns.


//Take lnked list (after transfrmation).
//Matrix: Allocate memory to an array of int *row of size row_num.
//Allocate memory for ints number of columns.
//Traverse the linked list and insert into matrix.
//Return the matrix.


//Free the linked_list.
{
    node[i][j].
}
