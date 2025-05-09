/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:31:05 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:54:51 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	ft_putchar_hexa(unsigned int nb, int flag)
{
	if (flag == 1)
		write(2, &HEXA_UPPER[nb], 1);
	else
		write(2, &HEXA_LOWER[nb], 1);
	return (1);
}

int	ft_putnbr_hexa(unsigned int nb, int flag)
{
	int	len;

	len = 0;
	if (nb > 15)
		len += ft_putnbr_hexa (nb >> 4, flag);
	len += ft_putchar_hexa(nb & 15, flag);
	return (len);
}
