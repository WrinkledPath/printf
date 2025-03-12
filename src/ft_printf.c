#include "libft.h"

int	type_division(const char id, va_list args);int	type_int(va_list args);
int	type_char(va_list args);
int	type_string(va_list args);
int	type_unsign_int(va_list args);

int	ft_printf(const char *s, ...)
{
	va_list args;
	int	i;
	int	count;

	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += type_division(s[++i], args);
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	type_division(const char id, va_list args)
{
	int	count;

	count = 0;
	if (id == 'i' || id == 'd')
		count += type_int(args);
	else if (id == 'c')
		count += type_char(args);
	else if (id == 's')
		count += type_string(args);
	else if (id == '%')
		count += write(1, "%", 1);
	else if (id == 'u')
		count += type_unsign_int(args);
	return (count);
}

int	type_int(va_list args)
{
	int	i;
	int	count;

	i = va_arg(args, int);
	count = ft_putnbr(i);
	return (count);
}

int	type_char(va_list args)
{
	char	c;
	int	count;

	c = va_arg(args, int);
	count = write(1, &c, 1);
	return (count);
}

int	type_string(va_list args)
{
	char	*s;
	int	count;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	count = ft_putstr(s);
	return (count);
}

int	type_unsign_int(va_list args)
{
	unsigned int	i;
	int	count;

	i = va_arg(args, unsigned int);
	count = ft_putunbr(i);
	return (count);
}


