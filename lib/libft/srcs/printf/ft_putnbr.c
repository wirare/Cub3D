/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:26:28 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:54:44 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(2, INT_MIN, 11);
		return (11);
	}
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
		len ++;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_putunsigned_nbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_putunsigned_nbr(nb / 10);
	}
	len += ft_putchar(nb % 10 + '0');
	return (len);
}
