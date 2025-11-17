/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:08:41 by msancar           #+#    #+#             */
/*   Updated: 2025/06/26 22:32:01 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[len] && s2[len] && s1[len] == s2[len] && len < n - 1)
	{
		len++;
	}
	return ((unsigned char)s1[len] - (unsigned char)s2[len]);
}
