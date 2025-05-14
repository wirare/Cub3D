/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:23:28 by jodougla          #+#    #+#             */
/*   Updated: 2025/05/14 12:10:46 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "ft_string.h"
#include <parsing.h>

void	print_error(char *error, char *error_msg)
{
	int	len_error;
	int	len_error_msg;
	int	i;

	len_error = ft_strlen(error);
	len_error_msg = ft_strlen(error_msg);
	i = 0;
	ft_printf("%s\n", error);
	while (i != len_error / 2)
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("\033[31m▲\n");
	i = 0;
	while (i != len_error / 2)
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("|\n");
	i = 0;
	while (i != len_error / 2)
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("|\n");
	if (len_error_msg  > len_error / 2)
		ft_printf("%s\n", error_msg);
	else
	{
		int	number_of_space = len_error / 2 - len_error_msg / 2;
		while(number_of_space != 0)
		{
			ft_printf(" ");
			number_of_space--;
		}
		ft_printf("%s\n", error_msg);
	}
}
