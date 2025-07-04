/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:29:55 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/04 20:36:50 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

void	set_color(t_parsing parsing, t_app *app)
{
	mlx_color	color;

	color = (mlx_color){.r = parsing.floor->r,
		.g = parsing.floor->g, .b = parsing.floor->b, .a = 0xFF};
	app->cub3d->ground_color = color.rgba;
	color = (mlx_color){.r = parsing.celling->r,
		.g = parsing.celling->g, .b = parsing.celling->b, .a = 0xFF};
	app->cub3d->sky_color = color.rgba;
}

int	check_tas(t_app *app, int tas)
{
	if (tas)
	{
		app->cub3d->tas = true;
		if (read_tas_file(&app->cub3d->tas_inputs))
		{
			delete_img(*app);
			return (1);
		}
	}
	return (0);
}
