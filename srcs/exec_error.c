/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:49:30 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 01:31:26 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <cub3d.h>

int	context_error(mlx_context mlx)
{
	if (!mlx)
	{
		ft_printf("Error\nMlx context failed\n");
		return (1);
	}
	return (0);
}

int	window_error(t_app app)
{
	if (!app.win)
	{
		mlx_destroy_context(app.mlx);
		ft_printf("Error\nMlx window failed\n");
		return (1);
	}
	return (0);
}

void	error_file(t_parsing parsing)
{
	ft_printf("Error\nMissing component in the map\n");
	free_parsing(parsing);
	exit (1);
}
