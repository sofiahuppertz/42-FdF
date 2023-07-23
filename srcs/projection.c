#include "../fdf.h"


t_point ***isometric_transformation(char ***matrix, int row_numb, int column_numb)
{
    //Allocate space for the 3D matrix
    t_point ***t_matrix;

    t_matrix = malloc(sizeof(t_point **) * row_numb + 1);
    if (!t_matrix)
        return (NULL);
    //Traverse char ***matrix
    t_matrix[row_numb] = NULL;
    for (int x = 0; x < row_numb; x++)
    {
        t_matrix[x] = malloc(sizeof(t_point *) * column_numb + 1);
        if (!t_matrix[x])
        {
            //free t_matrix.
            ft_printf("Memory allocation failed.\n");
            return(NULL);
        }
        t_matrix[x][column_numb] = NULL;
        for (int y = 0; y < column_numb; y++)
        {
            int z = ft_atoi(matrix[x][y]);
            t_matrix[x][y] = projected_point(x, y, z);
            if (!t_matrix[x][y])
                free_point_matrix(t_matrix);
        }
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

    x = x * 10;
    y = y * 10;
    z = z * 10;

    angle = 0.523599;
    isoX = (x - y) * cos(angle);
    isoY = -(z) + (x + y) * sin(angle);
    new_point = malloc(sizeof(t_point));
    if(!new_point)
    {
        ft_printf("Could not make new t_point\n");
        return (new_point);
    }     
    new_point->x = isoX + 500;
    new_point->y = isoY + 500;
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
