/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:08:11 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/01 19:55:53 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <stdbool.h>
#include <SDL2/SDL_scancode.h>

void	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
}

void	keydown_hook(int key, void *_app)
{
	t_app	*app;

	app = (t_app *)_app;
	if (key == SDL_SCANCODE_ESCAPE)
	{
		app->cub3d->end = true;
		mlx_loop_end(app->mlx);
	}
	if (!app->cub3d->tas)
		app->cub3d->inputs[key] = true;
}

void	keyup_hook(int key, void *_app)
{
	t_app	*app;

	app = (t_app *)_app;
	if (!app->cub3d->tas)
		app->cub3d->inputs[key] = false;
}

void	hooks(t_app *app)
{
	mlx_on_event(app->mlx, app->win, MLX_WINDOW_EVENT, window_hook, app->mlx);
	mlx_on_event(app->mlx, app->win, MLX_KEYDOWN, keydown_hook, app);
	mlx_on_event(app->mlx, app->win, MLX_KEYUP, keyup_hook, app);
}
