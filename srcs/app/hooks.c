/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:08:11 by ellanglo          #+#    #+#             */
/*   Updated: 2025/05/02 18:02:34 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <stdio.h>
#include <SDL2/SDL_scancode.h>

void	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
}

void	key_hooks(int key, void *_app)
{
	t_app		*app;
	t_player	*player;
	double		move_speed;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;

	app = (t_app *)_app;
	player = &app->cub3d->player;
	move_speed = MOVE_SPEED * app->cub3d->timing.delta_time;
	rot_speed = ROT_SPEED * app->cub3d->timing.delta_time;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(app->mlx);
	if (key == SDL_SCANCODE_W)
	{
		if (app->cub3d->map[(int)(player->pos.x + player->dir.x * move_speed)][(int)(player->pos.y)] == 0)
			player->pos.x += player->dir.x * move_speed;
		if (app->cub3d->map[(int)(player->pos.x)][(int)(player->pos.y + player->dir.y * move_speed)] == 0)
			player->pos.y += player->dir.y * move_speed;
	}
	if (key == SDL_SCANCODE_S)
	{
		if (app->cub3d->map[(int)(player->pos.x - player->dir.x * move_speed)][(int)(player->pos.y)] == 0)
			player->pos.x -= player->dir.x * move_speed;
		if (app->cub3d->map[(int)(player->pos.x)][(int)(player->pos.y - player->dir.y * move_speed)] == 0)
			player->pos.y -= player->dir.y * move_speed;
	}
	if (key == SDL_SCANCODE_A)
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y * sin(rot_speed);
		player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y * cos(rot_speed);
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos(rot_speed) - player->plane.y * sin(rot_speed);
		player->plane.y = old_plane_x * sin(rot_speed) + player->plane.y * cos(rot_speed);
	}
	if (key == SDL_SCANCODE_D)
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y * sin(-rot_speed);
		player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y * cos(-rot_speed);
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * cos(-rot_speed) - player->plane.y * sin(-rot_speed);
		player->plane.y = old_plane_x * sin(-rot_speed) + player->plane.y * cos(-rot_speed);
	}
}

void	hooks(t_app *app)
{
	mlx_on_event(app->mlx, app->win, MLX_WINDOW_EVENT, window_hook, app->mlx);
	mlx_on_event(app->mlx, app->win, MLX_KEYDOWN, key_hooks, app);
}
