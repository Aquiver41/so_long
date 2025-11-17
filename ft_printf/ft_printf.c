/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:04:23 by msancar           #+#    #+#             */
/*   Updated: 2025/08/02 18:04:02 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *c)
{
	int	len;

	len = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[len])
		len++;
	return (write(1, c, len));
}

static int	ft_type(const char c, va_list arguments)
{
	if (c == 'c')
		return (ft_put_char(va_arg(arguments, int)));
	else if (c == 's')
		return (ft_put_str(va_arg(arguments, char *)));
	else if (c == 'p')
		return (ft_put_ptr(va_arg(arguments, void *)));
	else if ((c == 'd' || c == 'i'))
		return (ft_put_int_dec(va_arg(arguments, int)));
	else if (c == 'u')
		return (ft_put_nbr_unsigned(va_arg(arguments, unsigned int)));
	else if ((c == 'x' || c == 'X'))
		return (ft_put_hex_up_x(va_arg(arguments, unsigned int), c));
	else if (c == '%')
		return (ft_put_char('%'));
	else
		return (-1);
}

static int	ft_hprintf(const char *format, va_list arguments)
{
	int	i;
	int	length;
	int	prnt;

	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			prnt = ft_type(format[i + 1], arguments);
			if (prnt == -1)
				return (-1);
			i += 2;
		}
		else
		{
			prnt = write(1, &format[i++], 1);
			if (prnt == -1)
				return (-1);
		}
		length += prnt;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		result;

	if (!format)
		return (-1);
	va_start(arguments, format);
	result = ft_hprintf(format, arguments);
	va_end(arguments);
	return (result);
}
