/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:49:30 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 00:36:59 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <cub3d.h>

int	context_error(mlx_context mlx)
{
	if (!mlx)
	{
		ft_printf("Error with the mlx\n");
		return (1);
	}
	return (0);
}

int	window_error(t_app app)
{
	if (!app.win)
	{
		mlx_destroy_context(app.mlx);
		ft_printf("ERRor with the mlx\n");
		return (1);
	}
	return (0);
}

void	error_file(t_parsing parsing)
{
	ft_printf("Missing component in the map\n");
	free_parsing(parsing);
	exit (1);
}
