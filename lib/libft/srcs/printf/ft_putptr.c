/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:09:37 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:55:49 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	ft_putptr(unsigned long str)
{
	int	len;

	if (!str)
	{
		write(2, "(nil)", 5);
		return (5);
	}
	len = 2;
	write (2, "0x", 2);
	len += ft_putnbr_mem(str, 'x');
	return (len);
}

int	ft_putnbr_mem(unsigned long str, int flag)
{
	int	len;

	len = 0;
	if (str > 15)
		len += ft_putnbr_mem(str >> 4, flag);
	len += ft_putchar_hexa(str & 15, flag);
	return (len);
}
