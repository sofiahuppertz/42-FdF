#include "ft_printf.h"

int display_hex_recursive(unsigned int num, char c)
{
	char *base;
	int idx;
	
	idx = 0;
	if (c == 'x')
        base = "0123456789abcdef";
    else if (c == 'X')
        base = "0123456789ABCDEF";
    if (num < 16)
    {
        idx += write(1, (base + num), 1);
    }
	if (num >= 16)
	{
		idx += display_hex_recursive(num / 16, c);
		idx += display_hex_recursive(num % 16, c);
	}
	return (idx);
}
