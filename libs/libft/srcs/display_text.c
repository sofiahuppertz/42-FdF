#include "ft_printf.h"

int display_text(char *str)
{
    char *start;

    start = str;
    if (str == NULL)
    {
        display_text("(null)");
        return (6);
    }
    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
    return(str - start);
}