/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:09 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:09:18 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_stdlib.h>

float	calcul_fnum(char *str, float num, int exp)
{
	while ((unsigned int)*str - 48 < 10)
	{
		num = num + ((*str - '0') * powf(10, exp));
		str++;
		exp--;
	}
	return (num);
}

float	ft_atof(char *str)
{
	float	num;
	int		sign;
	int		exp;

	num = 0;
	sign = 1;
	exp = -1;
	while ((unsigned int)*str - 8 < 6 || *str == 32)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((unsigned int)*str - 48 < 10)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (*str == '.' || *str == ',')
		str++;
	return (calcul_fnum(str, num, exp) * sign);
}
