#include "ft_printf.h"

int ft_printf(const char *str,...)
{
    va_list args;
    int len;

    // if (*str == '\0')
    //     return (0);
    len = 0;
    va_start(args, str);
    while (*str != '\0')
    {
        if (*str == '%')
        {
            str++;
            len += check_format(args, *str);
        }
        else
        {
            len += write(1, str, 1);
        }
        str++;
    }
    va_end(args);
    return (len);
}
