#include "fdf.h"

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
        ft_printf("Usage: ./fdf [map.fdf]\n");
        return (1);
    }
    file = open(argv[1], O_RDONLY);
    if (!file)
    {
        ft_printf("Could not open file\n");
        return (1);
    }
    matrix = parsing(file, &rows, &columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%s\n", matrix[i][j]);
        }
    }

}