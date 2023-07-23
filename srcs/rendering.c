#include "../fdf.h"

int    rendering(t_point ***matrix, int rows, int columns)
{
    //calculate how many pixels per row and how many pixels per column;
    t_data graphic;
    int i;
    int j;

    i = 0;
    j = 0;

    graphic.mlx = mlx_init();
    set_values(&graphic);
    
    while (i < rows - 1)   
    {
        while(j < columns - 1)
        {
            //draw lines... to the right and downwards.
            draw_line(&graphic, matrix[i][j]->x, matrix[i][j]->y, matrix[i][j + 1]->x, matrix[i][j + 1]->y);
            draw_line(&graphic, matrix[i][j]->x, matrix[i][j]->y, matrix[i + 1][j]->x, matrix[i + 1][j]->y);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(graphic.mlx, graphic.window, graphic.img, 0, 0);
    mlx_key_hook();
    mlx_loop(graphic.mlx);
    //pressing esc or red cross must end program.
    return (0);    
}


