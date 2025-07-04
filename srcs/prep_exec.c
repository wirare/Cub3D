/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:07:03 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 01:32:18 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app.h"
#include "ft_string.h"
#include "mlx.h"
#include <cub3d.h>

inline long	frame_counter(bool set)
{
	static long	fc = 0;

	if (set)
		fc++;
	return (fc);
}

static void	__update(void *_app)
{
	t_app	*app;

	app = (t_app *)_app;
	mouse_movement(app);
	movement(app->cub3d);
	rotation(app->cub3d);
	door(app->cub3d);
	reset_display(app);
	raycaster(app->cub3d);
	mlx_pixel_put_array(app->mlx, app->win, 0, 0,
		(mlx_color *)app->cub3d->pixels, HEIGHT * WIDTH);
	if (app->cub3d->update_num <= frame_counter(true)
		&& app->cub3d->update_num != -1)
		mlx_loop_end(app->mlx);
	draw_sprite(app);
	return ;
}

int	check_texture(t_app *app)
{
	return (!app->cub3d->textures[N].img || !app->cub3d->textures[S].img
		|| !app->cub3d->textures[W].img || !app->cub3d->textures[E].img
		|| !app->cub3d->textures[D].img || !app->cub3d->sprite[0]
		|| !app->cub3d->sprite[1] || !app->cub3d->sprite[2]
		|| !app->cub3d->sprite[3] || !app->cub3d->sprite[4]);
}

int	set_mlx(t_app *app, t_parsing *parsing)
{
	mlx_window_create_info	info;
	static t_cub3d			cub3d = {0};

	ft_memset(&info, 0, sizeof(mlx_window_create_info));
	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	info = (mlx_window_create_info){.width = WIDTH, .height = HEIGHT,
		.title = NAME};
	app->cub3d = &cub3d;
	app->mlx = mlx_init();
	if (context_error(app->mlx))
		return (1);
	app->win = mlx_new_window(app->mlx, &info);
	if (window_error(*app))
		return (1);
	set_texture(parsing, app);
	if (check_texture(app))
	{
		ft_printf("Error\nWhile opening the textures\n");
		delete_img(*app);
		return (1);
	}
	return (0);
}

void	prep_exec(t_parsing parsing, int tas)
{
	t_app					app;

	if (set_mlx(&app, &parsing))
		return ;
	if (check_tas(&app, tas))
		return ;
	set_color(parsing, &app);
	get_player_pos(parsing.map, &app.cub3d->player.pos, &app.cub3d->player.dir);
	app.cub3d->map_height = len_array(parsing.map);
	app.cub3d->map_width = max_line_len(parsing.map);
	app.cub3d->update_num = -1;
	pad_for_exec(parsing, &app);
	init_player_timing(app.cub3d);
	reset_display(&app);
	mlx_mouse_hide(app.mlx);
	hooks(&app);
	mlx_set_fps_goal(app.mlx, FPS);
	mlx_add_loop_hook(app.mlx, __update, &app);
	if (!app.cub3d->tas)
		mlx_loop(app.mlx);
	else
		execute_tas(&app);
	app_destroy(&app);
}
