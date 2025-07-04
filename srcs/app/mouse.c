/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:11:00 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:19:19 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void	get_mouse(t_app *app, t_vector *mouse_pos)
{
	int	i;
	int	j;

	mlx_mouse_get_pos(app->mlx, &i, &j);
	*mouse_pos = (t_vector){i, j};
}

void	mouse_movement(t_app *app)
{
	t_vector	mpos;
	double		dx;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;

	get_mouse(app, &mpos);
	dx = (double)mpos.x - (WIDTH / 2.0);
	if (dx != 0.0)
	{
		rot_speed = dx * MOUSE_ROT_SPEED * app->cub3d->timing.delta_time * -1;
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
