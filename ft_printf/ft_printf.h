/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:54:03 by msancar           #+#    #+#             */
/*   Updated: 2025/08/02 17:57:54 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_put_ptr(void *ptr);
int	ft_put_str(char *c);
int	ft_put_char(char c);
int	ft_put_nbr_unsigned(unsigned int n);
int	ft_put_int_dec(int n);
int	ft_put_hex_up_x(unsigned int n, int type);

#endif
