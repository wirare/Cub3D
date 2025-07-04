/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:29:06 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:34:34 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void	run_tas(t_app *app, bool *inputs, int **tas_inputs_copy)
{
	int	*frame_inputs;
	int	frame_count;
	int	current;

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
}

void	execute_tas(t_app *app)
{
	bool	*inputs;

	inputs = app->cub3d->inputs;
	if (!app->cub3d->tas_inputs)
		return ;
	run_tas(app, inputs, app->cub3d->tas_inputs);
	memset(inputs, 0, sizeof(bool) * SDL_NUM_SCANCODES);
	app->cub3d->update_num = -1;
	app->cub3d->tas = 0;
	mlx_loop(app->mlx);
}
