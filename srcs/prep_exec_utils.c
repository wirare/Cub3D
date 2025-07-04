/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:20:07 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/04 20:23:55 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
