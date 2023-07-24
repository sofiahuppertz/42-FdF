#include "../fdf.h"

int    rendering(t_point ***matrix, int rows, int columns)
{
    //calculate how many pixels per row and how many pixels per column;
    t_data graphic;
    int i;
    int j;

    i = 0;

    graphic.mlx = mlx_init();
    set_values(&graphic);
    
    while (i < rows)   
    {
        j = 0;
        while(j < columns - 1)
        {
            //draw lines... to the right and downwards.
            my_mlx_pixel_put(&graphic,  matrix[i][j]->x,  matrix[i][j]->y, 0x00FFFFFF);
            draw_line(&graphic, matrix[i][j]->x, matrix[i][j]->y, matrix[i][j + 1]->x, matrix[i][j + 1]->y);
            mlx_put_image_to_window(graphic.mlx, graphic.window, graphic.img, 0, 0);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < columns)   
    {
        j = 0;
        while(j < rows -1)
        {
            draw_line(&graphic, matrix[j][i]->x, matrix[j][i]->y, matrix[j + 1][i]->x, matrix[j + 1][i]->y);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(graphic.mlx, graphic.window, graphic.img, 0, 0);
    mlx_loop(graphic.mlx);
    //pressing esc or red cross must end program.
    return (0);    
}


