/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/14 21:56:58 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

static void __update(void *_app)
{
	t_app	*app;

	app = (t_app *)_app;
	mlx_clear_window(app->mlx, app->win, (mlx_color){.rgba = 60});
	return ;
}

int	main(void)
{
	t_app	app;

	app_init(&app);
	mlx_set_fps_goal(app.mlx, FPS);
	mlx_add_loop_hook(app.mlx, __update, &app);
	mlx_loop(app.mlx);
	app_destroy(&app);
}
