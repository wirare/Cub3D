/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:20:32 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:46:24 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_fd.h>

void	close_fd(int num_fd, ...)
{
	va_list	list_fd;
	int		fd;

	va_start(list_fd, num_fd);
	while (num_fd != 0)
	{
		fd = va_arg(list_fd, int);
		if (fd > 2)
			close (fd);
		num_fd--;
	}
	va_end(list_fd);
}
