/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 04:27:07 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:20:56 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_str.h>

static int	count_num(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i ++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_num(n);
	str = ft_calloc(size + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (n <= 0)
	{
		n = -n;
		str [0] = '-';
	}
	while (n >= 10)
	{
		str[size] = n % 10 + '0';
		n = n / 10;
		size --;
	}
	str[size] = n % 10 + '0';
	return (str);
}
