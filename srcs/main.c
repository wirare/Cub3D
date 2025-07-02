/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/02 17:37:35 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "mlx_extended.h"
#include <SDL2/SDL_scancode.h>
#include <app.h>
#include <string.h>
#include <sys/time.h>

static inline long	frame_counter(bool set)
{
	static long	fc = 0;

	if (set)
		fc++;
	return (fc);
}

suseconds_t	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void	__update(void *_app)
{
	t_app	*app;

	app = (t_app *)_app;
	printf("Player rotation : %f %f\n", app->cub3d->player.dir.x, app->cub3d->player.dir.y);
	reset_display(app);
	raycaster(app->cub3d);
	mlx_pixel_put_array(app->mlx, app->win, 0, 0,
		(mlx_color *)app->cub3d->pixels, HEIGHT * WIDTH);
	mouse_movement(app);
	movement(app->cub3d);
	rotation(app->cub3d);
	door(app->cub3d);
	if (app->cub3d->update_num <= frame_counter(true)
		&& app->cub3d->update_num != -1)
		mlx_loop_end(app->mlx);
	return ;
}

static void	execute_tas(t_app *app)
{
	int		*frame_inputs;
	bool	*inputs;
	int		current;
	int		frame_count;
	int		**tas_inputs_copy;

	inputs = app->cub3d->inputs;
	if (!app->cub3d->tas_inputs)
		return ;
	tas_inputs_copy = app->cub3d->tas_inputs;
	frame_inputs = *tas_inputs_copy;
	while (frame_inputs != NULL)
	{
		if (app->cub3d->end)
			return ;
		frame_count = *frame_inputs;
		frame_inputs++;
		current = *frame_inputs;
		memset(inputs, 0, sizeof(bool) * SDL_NUM_SCANCODES);
		while (current != -1)
		{
			inputs[current] = true;
			frame_inputs++;
			current = *frame_inputs;
		}
		tas_inputs_copy++;
		frame_inputs = *tas_inputs_copy;
		app->cub3d->update_num = frame_counter(false) + frame_count;
		mlx_loop(app->mlx);
	}
	memset(inputs, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	app->cub3d->update_num = -1;
	app->cub3d->tas = 0;
	mlx_loop(app->mlx);
}

int	main(int ac, char **av)
{
	t_app			app;
	static t_cub3d	cub3d = {0};

	(void)ac;
	app_init(&app);
	app.cub3d = &cub3d;
	if (init_cub3d(&app, av[1]))
		app_destroy(&app);
	hooks(&app);
	mlx_set_fps_goal(app.mlx, FPS);
	mlx_add_loop_hook(app.mlx, __update, &app);
	if (!app.cub3d->tas)
		mlx_loop(app.mlx);
	else
		execute_tas(&app);
	app_destroy(&app);
}
