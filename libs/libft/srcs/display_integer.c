#include "ft_printf.h"

int display_integer( int num)
{
    long int nbr;
    char digit;
    int idx;

    idx = 0;
    nbr = num;
    if (num < 0)
    {
        idx += write(1, "-", 1);
        nbr *= -1;
    }
    if (nbr < 10)
    {
        digit = nbr + '0';
        idx += write(1, &digit, 1);
    }
    if (nbr >= 10)
    {
        idx += display_integer(nbr / 10);
        idx += display_integer(nbr % 10);
    }
    return (idx);   
}
