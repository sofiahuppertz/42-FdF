#include "libft.h"

size_t str_array_length(const char **str_array)
{
    size_t i;
    
    i = 0;
    while (str_array[i] != 0)
    {
        i++;
    }
    return (i);
}
