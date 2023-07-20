#include "ft_printf.h"

int display_unsigned_int(unsigned int num)
{
    int idx;
    char digit;

    idx = 0;
    if (num < 10)
    {
        digit = num + '0';
        idx = write(1, &digit, 1);
    }
    if (num >= 10)
    {
        idx += display_unsigned_int(num / 10);
        idx += display_unsigned_int(num % 10);
    }
    return (idx);
}