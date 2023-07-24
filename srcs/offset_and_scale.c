#include "../fdf.h"


void    fit_grid_to_window(t_point ***grid, int height, int width)
{
    t_layout *layout;
    int i;
    int j;

    layout = malloc(sizeof(t_layout));
    if (!layout)
        return;
    set_extent(layout, grid, height, width);
    set_scale(layout);
    set_offset(layout);
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
        
            grid[i][j]->x = floor((layout->scale * (grid[i][j]->x - layout->min_x)) + layout->offset_x);
            grid[i][j]->y = floor((layout->scale * (grid[i][j]->y - layout->min_y) + layout->offset_y));
            j++;
        }
        i++;
    }
    free(layout);

}

void    set_extent(t_layout *layout, t_point ***grid, int height, int width)
{
    int i;
    int j;
    
    layout->max_x = INT_MIN;
    layout->max_y = INT_MIN;
    layout->min_x = INT_MAX;
    layout->min_y = INT_MAX;
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (grid[i][j]->x > layout->max_x)
                layout->max_x = grid[i][j]->x;
            if (grid[i][j]->y > layout->max_y)
                layout->max_y = grid[i][j]->y;
            if (grid[i][j]->x < layout->min_x)
                layout->min_x = grid[i][j]->x;
            if (grid[i][j]->y < layout->min_y)
                layout->min_y = grid[i][j]->y; 
            j++;
        }
        i++;
    }
    layout->height = layout->max_y - layout->min_y;
    layout->width = layout->max_x - layout->min_x;
}

void    set_scale(t_layout *layout)
{
    double scale;

    scale =  (WINDOW_WIDTH - MARGIN) / layout->width;
    scale = scale < ((WINDOW_HEIGHT - MARGIN)/ layout->height) ? scale : (WINDOW_HEIGHT - MARGIN)/ layout->height;

    layout->scale = scale;
}

void set_offset(t_layout *layout)
{
    layout->offset_x = ( WINDOW_WIDTH - (layout->width * layout->scale)) / 2;
    layout->offset_y = (WINDOW_HEIGHT- (layout->height * layout->scale)) / 2;

}
