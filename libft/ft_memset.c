/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:06:56 by msancar           #+#    #+#             */
/*   Updated: 2025/06/25 15:19:58 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		((unsigned char *)s)[len] = c;
		len++;
	}
	return (s);
}
