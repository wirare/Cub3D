/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_app.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:45:13 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/14 21:45:18 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <string.h>
#include <stdlib.h>

void	app_init(t_app *app)
{
	mlx_window_create_info info;

	memset(&info, 0, sizeof(mlx_window_create_info));
	info = (mlx_window_create_info){
		.width = WIDTH,
		.height = HEIGHT,
		.title = NAME,
	};
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, &info);
}

void	app_destroy(t_app *app)
{
	mlx_clear_window(app->mlx, app->win, (mlx_color){.rgba = 0});
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_context(app->mlx);
	exit(0);
}
