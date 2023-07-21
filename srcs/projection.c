#include "../fdf.h"


t_point ***isometric_transformation(char ***matrix, int row_numb, int column_numb)
{
    //Allocate space for the 3D matrix
    t_point ***t_matrix;

    t_matrix = malloc(sizeof(t_point *) * row_numb);
    if (!t_matrix)
        return (NULL);
    //Traverse char ***matrix
    for (int x = 0; x < row_numb; x++)
    {
        for (int y = 0; y < column_numb; y++)
        {
            int z = ft_atoi(matrix[x][y]);
            t_matrix[x][y] = edge_projection(x, y, z);
        }
    }
    return (t_matrix);
    //Transform each char * to int.
    //Project each point (t_point).
}

t_point *edge_projection(int x, int y, int z)
{
    t_point *new_point;
    double cx;
    double cy;

    cx = ((double)x * sqrt(3) - (double)z * sqrt(3)) / sqrt(6);
    cy = ((double)x + 2 * y + z) / sqrt(6);

    new_point = malloc(sizeof(t_point));
    if(!new_point)
    {
        ft_printf("Could not make new t_point\n");
        return (new_point);
    }     
    new_point->x = floor(cx);
    new_point->y = floor(cy);
    return (new_point);
}