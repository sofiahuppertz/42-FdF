#include "ft_printf.h"

int display_char(unsigned int n)
{
    char c;

    c = (char)n;
    return (write(1, &c, 1));
}