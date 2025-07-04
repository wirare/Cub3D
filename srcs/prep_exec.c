/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:07:03 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/04 17:08:04 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app.h"
#include "ft_string.h"
#include "mlx.h"
#include <cub3d.h>

void	transform_map_for_exec(t_app *app, char **pad)
{
	int	i;
	int	j;

	i = 0;
	app->cub3d->map = malloc (app->cub3d->map_height * sizeof(t_wall *));
	while (pad[i])
	{
		j = 0;
		app->cub3d->map[i] = malloc(app->cub3d->map_width * sizeof(t_wall));
		while (pad[i][j])
		{
			if (pad [i][j] == '1')
				app->cub3d->map[i][j] = WALL;
			else if (pad [i][j] == '0' || pad[i][j] == 'W' || pad[i][j] == 'E'
					|| pad[i][j] == 'N' || pad[i][j] == 'S')
				app->cub3d->map[i][j] = EMPTY;
			else if (pad [i][j] == 'D')
				app->cub3d->map[i][j] = DOOR_CLOSE;
			j++;
		}
		i++;
	}
	ft_free(pad);
}

void	pad_for_exec(t_parsing parsing, t_app *app)
{
	char	**pad;
	int		i;
	int		j;

	i = -1;
	pad = malloc((app->cub3d->map_height + 1) * sizeof(char *));
	while (++i < app->cub3d->map_height)
	{
		pad[i] = malloc(app->cub3d->map_width + 1 * sizeof(char));
		j = 0;
		while (parsing.map[i][j])
		{
			if (parsing.map[i][j] == ' ')
				pad[i][j] = '1';
			else
				pad[i][j] = parsing.map[i][j];
			j++;
		}
		while (j < app->cub3d->map_width)
			pad[i][j++] = '1';
		pad[i][j] = '\0';
	}
	pad[app->cub3d->map_height] = NULL;
	transform_map_for_exec(app, pad);
}

void	get_dir(char **map, int i, int j, t_vector *dir)
{
	if (map[i][j] == NORTH)
	{
		(*dir).x = 0;
		(*dir).y = -1;
	}
	if (map[i][j] == SOUTH)
	{
		(*dir).x = 0;
		(*dir).y = 1;
	}
	if (map[i][j] == WEST)
	{
		(*dir).x = -1;
		(*dir).y = 0;
	}
	if (map[i][j] == EAST)
	{
		(*dir).x = 1;
		(*dir).y = 0;
	}
}

void	get_player_pos(char **map, t_vector *pos, t_vector *dir)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == NORTH || map[i][j] == SOUTH || map[i][j] == WEST
				|| map[i][j] == EAST)
			{
				get_dir(map, i, j, dir);
				(*pos).x = j;
				(*pos).y = i;
				return ;
			}
		}
	}
}

void	delete_img(t_app app)
{
	ft_printf("Error while opening the textures\n");
	if (app.cub3d->textures[N].img)
		free(app.cub3d->textures[N].img);
	if (app.cub3d->textures[S].img)
		free(app.cub3d->textures[S].img);
	if (app.cub3d->textures[W].img)
		free(app.cub3d->textures[W].img);
	if (app.cub3d->textures[E].img)
		free(app.cub3d->textures[E].img);
	if (app.cub3d->textures[D].img)
		free(app.cub3d->textures[D].img);
	mlx_destroy_window(app.mlx, app.win);
	mlx_destroy_context(app.mlx);
}

void	set_color(t_parsing parsing, t_app *app)
{
	mlx_color	color;

	color = (mlx_color){.r = parsing.floor->r,
		.g = parsing.floor->g, .b = parsing.floor->b, .a = 0xFF};
	app->cub3d->ground_color = color.rgba;
	color = (mlx_color){.r = parsing.celling->r,
		.g = parsing.celling->g, .b = parsing.celling->b, .a = 0xFF};
	app->cub3d->sky_color = color.rgba;
}

static inline long	frame_counter(bool set)
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

void	prep_exec(t_parsing parsing, int tas)
{
	t_app					app;
	static t_cub3d			cub3d = {0};
	mlx_window_create_info	info;

	ft_memset(&info, 0, sizeof(mlx_window_create_info));
	ft_memset(&cub3d, 0, sizeof(t_cub3d));
	info = (mlx_window_create_info){.width = WIDTH, .height = HEIGHT,
		.title = NAME};
	app.cub3d = &cub3d;
	app.mlx = mlx_init();
	if (!app.mlx)
	{
		ft_printf("Error with the mlx\n");
		return ;
	}
	app.win = mlx_new_window(app.mlx, &info);
	if (!app.win)
	{
		mlx_destroy_window(app.mlx, app.win);
		ft_printf("Error with the mlx\n");
		return ;
	}
	set_texture(&parsing, app);
	if (!app.cub3d->textures[N].img || !app.cub3d->textures[S].img
		|| !app.cub3d->textures[W].img || !app.cub3d->textures[E].img)
	{
		delete_img(app);
		return ;
	}
	if (tas)
	{
		app.cub3d->tas = true;
		if (read_tas_file(&app.cub3d->tas_inputs))
		{
			delete_img(app);
			return ;
		}
	}
	set_color(parsing, &app);
	get_player_pos(parsing.map, &app.cub3d->player.pos, &app.cub3d->player.dir);
	app.cub3d->map_height = len_array(parsing.map);
	app.cub3d->map_width = max_line_len(parsing.map);
	app.cub3d->update_num = -1;
	app.cub3d->player.plane = (t_vector) {0, 0.85};
	pad_for_exec(parsing, &app);
	reset_display(&app);
	init_player_timing(&cub3d);
	mlx_mouse_hide(app.mlx);
	hooks(&app);
	mlx_set_fps_goal(app.mlx, FPS);
	mlx_add_loop_hook(app.mlx, __update, &app);
	if (!app.cub3d->tas)
		mlx_loop(app.mlx);
	else
		execute_tas(&app);
	app_destroy(&app);
	//et le loop hook la mlx loop les hook case et event
}
