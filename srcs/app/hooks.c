/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:08:11 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/14 22:09:55 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void	window_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
}

void	hooks(t_app *app)
{
	mlx_on_event(app->mlx, app->win, MLX_WINDOW_EVENT, window_hook, app->mlx);
}
