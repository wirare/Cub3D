/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:29:55 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 01:32:37 by jodougla         ###   ########.fr       */
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
			ft_printf("Error\nWhile reading the tas file\n");
			delete_img(*app);
			return (1);
		}
	}
	return (0);
}

void	init_player_timing(t_cub3d *cub3d)
{
	t_vector	dir;

	dir = cub3d->player.dir;
	cub3d->player.plane = (t_vector){dir.y * 0.85, -dir.x * 0.85};
	cub3d->timing = (t_timing){0, get_ms(), 0};
}
