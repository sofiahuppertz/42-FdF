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
    matrix = parsing(file, &rows, &columns);
    close(file);
    if (matrix)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] != NULL)
                printf("%s\n", matrix[i][j]);
            }
        }
    }
    return (0);
}