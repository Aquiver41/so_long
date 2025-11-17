/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:05:56 by msancar           #+#    #+#             */
/*   Updated: 2025/06/26 22:28:55 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d2;
	const unsigned char	*s2;

	if ((!dest && !src) || n == 0)
		return (dest);
	d2 = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	if (d2 < s2)
	{
		while (n--)
		{
			*d2++ = *s2++;
		}
	}
	else
	{
		d2 += n;
		s2 += n;
		while (n--)
		{
			*(--d2) = *(--s2);
		}
	}
	return (dest);
}
