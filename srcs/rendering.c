#include "../fdf.h"

int    wireframe_rendering(t_point ***matrix, int rows, int columns)
{
    //calculate how many pixels per row and how many pixels per column;
    t_data graphic;

    graphic = intialize_image(graphic);
    
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            my_mlx_pixel_put(&graphic, matrix[i][j]->x, matrix[i][j]->y, 0x00FFFFFF);
        }
    }
    mlx_put_image_to_window(graphic.mlx, graphic.window, graphic.img, 0, 0);
    mlx_loop(graphic.mlx);
    return (0);    
}


