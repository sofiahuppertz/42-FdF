#include "../fdf.h"


t_point ***isometric_transformation(char ***matrix, int row_numb, int column_numb)
{
    //Allocate space for the 3D matrix
    t_point ***t_matrix;
    int i;
    int j;

    t_matrix = malloc(sizeof(t_point **) * row_numb + 1);
    if (!t_matrix)
        return (NULL);
    //Traverse char ***matrix
    t_matrix[row_numb] = NULL;
    i = 0;
    while (i < row_numb)
    {
        t_matrix[i] = malloc(sizeof(t_point *) * column_numb + 1);
        if (!t_matrix[i])
        {
            //free t_matrix.
            ft_printf("Memory allocation failed.\n");
            return(NULL);
        }
        t_matrix[i][column_numb] = NULL;
        j = 0;
        while (j < column_numb)
        {
            int z = ft_atoi(matrix[i][j]);
            t_matrix[i][j] = projected_point(i, j, z);
            if (!t_matrix[i][j])
                free_point_matrix(t_matrix);
            j++;
        }
        i++;
    }
    return (t_matrix);
    //Transform each char * to int.
    //Project each point (t_point).
}

t_point *projected_point(int x, int y, int z)
{
    t_point *new_point;
    double angle;
    int isoX;
    int isoY;


    //angle = 0.523599;
    angle = 0.45 * 100;
    isoX = double(x - y) * cos(angle * 3.14157 / 180);
    isoY = -1.0 * (z) + double(x + y) * sin(angle * 3.14157 / 180);
    new_point = malloc(sizeof(t_point));
    if(!new_point)
    {
        ft_printf("Could not make new t_point\n");
        return (new_point);
    }     
    new_point->x = isoX;
    new_point->y = isoY;
    return (new_point);
}

void free_point_matrix(t_point ***matrix)
{
    int i = 0;
    int j = 0;

    if (!matrix) return;

    while (matrix[i] != NULL)
    {
        j = 0;
        while (matrix[i][j] != NULL)
        {
            free(matrix[i][j]);
            j++;
        }
        free(matrix[i]);
        i++;
    }
    free(matrix);
}


//Offset:
//check for min and max values of x and y.
