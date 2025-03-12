#include "libft.h"

int     ft_putstr(char *s) 
{
        int     i;  

        i = 0;
        while (s[i])
                i += write(1, &s[i], 1); 
        return (i);
}

