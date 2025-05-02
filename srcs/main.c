/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/30 17:46:52 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "mlx_extended.h"
#include <app.h>
#include <sys/time.h>

suseconds_t	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void __update(void *_app)
{
	t_app	*app;

	app = (t_app *)_app;
	reset_display(app->cub3d);
	raycaster(app->cub3d);
	mlx_pixel_put_array(app->mlx, app->win, 0, 0, app->cub3d->pixels, HEIGHT * WIDTH);
	return ;
}

int	main(void)
{
	t_app	app;
	static t_cub3d	cub3d = {0};

	app_init(&app);
	app.cub3d = &cub3d;
	init_cub3d(&app);
	hooks(&app);
	mlx_set_fps_goal(app.mlx, FPS);
	mlx_add_loop_hook(app.mlx, __update, &app);
	mlx_loop(app.mlx);
	app_destroy(&app);
}
