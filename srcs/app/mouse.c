/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:11:00 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/02 17:40:21 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void	mouse_movement(t_app *app)
{
	int		x;
	int		y;
	double	dx;
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	mlx_mouse_get_pos(app->mlx, &x, &y);
	dx = (double)x - (WIDTH / 2.0);
	if (dx != 0.0)
	{
		rot_speed = MOUSE_ROT_SPEED * app->cub3d->timing.delta_time;
		if (dx > 0)
			rot_speed = -rot_speed;

		old_dir_x = app->cub3d->player.dir.x;
		app->cub3d->player.dir.x = old_dir_x * cos(rot_speed)
		                        - app->cub3d->player.dir.y * sin(rot_speed);
		app->cub3d->player.dir.y = old_dir_x * sin(rot_speed)
		                        + app->cub3d->player.dir.y * cos(rot_speed);
		old_plane_x = app->cub3d->player.plane.x;
		app->cub3d->player.plane.x = old_plane_x * cos(rot_speed)
		                          - app->cub3d->player.plane.y * sin(rot_speed);
		app->cub3d->player.plane.y = old_plane_x * sin(rot_speed)
		                          + app->cub3d->player.plane.y * cos(rot_speed);
	}
}

