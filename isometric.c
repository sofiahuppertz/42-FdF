#include "fdf.h"


t_point **isometric_transformation(char **matrix, int row_numb, int column_numb)
{
    //Allocate space for the 3D matrix
    t_point **tridimensional;

    tridimensional = malloc(sizeof(t_point *) * row_numb);
    if (!tridimensional)
        return (NULL);
    //Traverse char ***matrix
    for (int y = 0; y < row_numb; y++)
    {
        for (int x = 0; x < column_numb; x++)
        {
            int z = ft_atoi(matrix[y][x]);
            tridimensional[y][x] = edge_projection(x, y, z);
        }
    }
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
        return (NULL);
    new_point.x = floor(cx);
    new_point.y = floor(cy);

    return (new_point);
}