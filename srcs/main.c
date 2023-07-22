#include "../fdf.h"

//1. Parsing file to matrix.
//2. Making 3D isometric matrix from the 2D matrix.
//3. Rendering: display  wireframe isometric model.
int main(int argc, char *argv[])
{
    int file;
    int rows;
    int columns;
    char ***matrix;
    t_point ***t_matrix;

    if (argc != 2)
    {
        ft_printf("Usage: ./fdf [map]\n");
        return (1);
    }
    file = open(argv[1], O_RDONLY);
    if (file == -1)
    {
        ft_printf("Could not open file\n");
        return (1);
    }
    rows = 0;
    columns = 0;
    matrix = parsing(file, &rows, &columns);
    if (matrix)
    {
       ft_printf("Matrix parsed ok.\nWhat it looks like:\n");
       ft_printf("Number of rows: %i\nNumber of columns: %i\n", rows, columns);
       for (int n = 0; n < rows; n++)
            for (int m = 0; m < columns; m++)
                ft_printf("%s ", matrix[n][m]);
            ft_printf("\n");
    }

    t_matrix = isometric_transformation(matrix, rows, columns);
    if (matrix)
    {
        ft_printf("Isometric transformetion worked.\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                printf(" %i, %i, ", t_matrix[i][j]->x, t_matrix[i][j]->y);
            }
        }
    }
    return (0);
}