/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:49:22 by jodougla          #+#    #+#             */
/*   Updated: 2025/04/12 16:34:39 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	ft_putchar(int c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	char		*tmp_str;

	if (str == NULL)
	{
		write (2, "(null)", 6);
		return (6);
	}
	tmp_str = str;
	while (*tmp_str)
		tmp_str++;
	write(2, str, tmp_str - str);
	return (tmp_str - str);
}
