/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:48:56 by ywagner           #+#    #+#             */
/*   Updated: 2025/03/20 14:53:09 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
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

int	type_div(const char id, va_list args)
{
	int	count;

	count = 0;
	if (id == '\0')
		return (count);
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
