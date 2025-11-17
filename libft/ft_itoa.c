/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:19:26 by msancar           #+#    #+#             */
/*   Updated: 2025/07/06 14:05:48 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlen(int n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (num <= 0)
	{
		len = 1;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	convert_to_str(char *str, long num, int len)
{
	str[len] = '\0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	num = n;
	if (!str)
		return (0);
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	convert_to_str(str, num, len);
	return (str);
}
