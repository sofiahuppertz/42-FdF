#include "../fdf.h"

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

t_data   intialize_image(t_data init)
{
    init.mlx = mlx_init();
    init.window = mlx_new_window(init.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
    init.img = mlx_new_image(init.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    init.addr = mlx_get_data_addr(init.img, &init.bits_per_pixel, &init.line_length, &init.endian);

    return init;
}