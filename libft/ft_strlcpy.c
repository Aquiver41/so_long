/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:07:46 by msancar           #+#    #+#             */
/*   Updated: 2025/11/12 13:18:10 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[size])
	{
		src[i] = dst[size];
		i++;
		size++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
