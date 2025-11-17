/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:20:14 by msancar           #+#    #+#             */
/*   Updated: 2025/08/02 18:00:06 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

static int	ft_hex(uintptr_t n)
{
	int		count;
	int		temp;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		temp = ft_hex(n / 16);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	else
		count++;
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int			count;
	int			temp;
	uintptr_t	address;

	address = (uintptr_t)ptr;
	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	temp = write(1, "0x", 2);
	if (temp == -1)
		return (-1);
	count += temp;
	count += ft_hex(address);
	return (count);
}

int	ft_put_int_dec(int n)
{
	int	len;
	int	value;

	len = 0;
	if (n == 0)
		return (ft_put_char('0'));
	if (n == -2147483648)
		return (ft_put_str("-2147483648"));
	if (n < 0)
	{
		if (ft_put_char('-') == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n >= 10)
	{
		value = ft_put_int_dec(n / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_put_char("0123456789"[n % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_put_nbr_unsigned(unsigned int n)
{
	int	len;
	int	value;

	len = 0;
	if (n >= 10)
	{
		value = ft_put_nbr_unsigned(n / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_put_hex_up_x(unsigned int n, int type)
{
	int		count;
	int		temp;
	char	*hex;

	count = 0;
	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		temp = ft_put_hex_up_x(n / 16, type);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}
