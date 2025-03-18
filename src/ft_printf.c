#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return(-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (count);
			i++;
			count += type_div(str[i], args);
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int		type_div(const char id, va_list args)
{
	int		count;
	
	count = 0;
	if (id == 'c')
		count += ft_putchar(va_arg(args, int));
	if (id == 's')
		count += ft_putstr(va_arg(args, const char *));
	if (id == 'p')
		count += print_ptr((unsigned long)va_arg(args, void *));
	if (id == 'i' || id == 'd')
		count += print_nbr(va_arg(args, int), DECIMAL);
	if (id == 'u')
		count += print_unbr(va_arg(args, unsigned int), DECIMAL);
	if (id == 'x')
		count += print_unbr((unsigned int)va_arg(args, unsigned int), HEX_MIN);
	if (id == 'X')
		count += print_unbr((unsigned int)va_arg(args, unsigned int), HEX_MAY);
	if (id == '%')
		count += ft_putchar('%');
	return (count);
}

int		ft_putchar(const char c)
{	
	return(write(1, &c, 1));
}

int		ft_putstr(const char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return(write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;		
	}
	return (i);
}

int		print_nbr(long n, const char *base)
{
	int				count;
	unsigned long	len_base;
	unsigned long	num;
	len_base = ft_strlen(base);
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		num = (unsigned long)(-(n + 1)) + 1;
	}
	else
		num = (unsigned long)n;
	if (num >= len_base)
	{
		count += print_nbr(num / len_base, base);
	}
	count += ft_putchar(base[num % len_base]);
	return (count);
}

int		print_unbr(unsigned long n, const char *base)
{
	int		count;
	unsigned long		len_base;

	len_base = ft_strlen(base);
	count = 0;
	if (n >= len_base)
	{
		count += print_unbr(n / len_base, base);
	}
	count += ft_putchar(base[n % len_base]);
	return (count);
}

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int		print_ptr(unsigned long p)
{
	int		count;

	count = 0;
	if (p == 0)
		return (write(1, "(nil)", 5)); 
	count += write(1, "0x", 2);
	count += print_unbr(p, HEX_MIN);
	return (count);
}
