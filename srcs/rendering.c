#include "../fdf.h"

int    wireframe_rendering(t_point ***matrix, int rows, int columns)
{
    //calculate how many pixels per row and how many pixels per column;
    t_data wireframe;

    (void)matrix;
    (void)rows;
    (void)columns;
    wireframe.mlx = mlx_init();
    wireframe.window = mlx_new_window(wireframe.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
    wireframe.img = mlx_new_image(wireframe.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    wireframe.addr = mlx_get_data_addr(wireframe.img, &wireframe.bits_per_pixel, &wireframe.line_length, &wireframe.endian);
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            my_mlx_pixel_put(&wireframe, matrix[i][j]->x, matrix[i][j]->y, 0x00FFFFFF);
        }
    }
    mlx_put_image_to_window(wireframe.mlx, wireframe.window, wireframe.img, 0, 0);
    mlx_loop(wireframe.mlx);
    return (0);    
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    if (x < 0 || y < 0 || x > WINDOW_WIDTH - 1 || y > WINDOW_HEIGHT - 1)
    {
        return;
    }
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
