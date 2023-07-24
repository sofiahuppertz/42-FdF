#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  set_values(t_data *init)
{
    init->window = mlx_new_window(init->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
    init->img = mlx_new_image(init->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    init->addr = mlx_get_data_addr(init->img, &init->bits_per_pixel, &init->line_length, &init->endian);
}

void	draw_line(t_data *data, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while ((x0 != x1) || (y0 != y1))
	{
        if (x0 > 0 && x0 < WINDOW_WIDTH && y0 > 0 && y0 < WINDOW_HEIGHT)
		    my_mlx_pixel_put(data, x0, y0, 0x0000FFFF);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err = err - dy;
			x0 = x0 + sx;
		}
		if (e2 < dx)
		{
			err = err + dx;
			y0 = y0 + sy;
		}
	}
}