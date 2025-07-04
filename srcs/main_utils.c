/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:38:20 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 01:25:21 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <cub3d.h>

void	set_parsing(t_parsing *parsing)
{
	parsing->no.path = NULL;
	parsing->so.path = NULL;
	parsing->ea.path = NULL;
	parsing->we.path = NULL;
	parsing->dt.path = NULL;
	parsing->floor = NULL;
	parsing->celling = NULL;
	parsing->map = NULL;
}

void	free_parsing(t_parsing parsing)
{
	if (parsing.no.path)
		free(parsing.no.path);
	if (parsing.so.path)
		free(parsing.so.path);
	if (parsing.ea.path)
		free(parsing.ea.path);
	if (parsing.we.path)
		free(parsing.we.path);
	if (parsing.dt.path)
		free(parsing.dt.path);
	if (parsing.floor)
		free(parsing.floor);
	if (parsing.celling)
		free(parsing.celling);
}

int	check_argc(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 3 && !ft_strncmp(argv[2], "--tas", 6))
			return (1);
		ft_printf("Error\nNot the right number of argument, put two argument, \
exemple :./Cub3d path_to_the_map\n");
		exit (1);
	}
	return (0);
}

int	set_texture(t_parsing *parsing, t_app *app)
{
	if (open_img(app, parsing->no.path, &app->cub3d->textures[N]))
		return (1);
	if (open_img(app, parsing->so.path, &app->cub3d->textures[S]))
		return (1);
	if (open_img(app, parsing->we.path, &app->cub3d->textures[W]))
		return (1);
	if (open_img(app, parsing->ea.path, &app->cub3d->textures[E]))
		return (1);
	if (open_img(app, parsing->dt.path, &app->cub3d->textures[D]))
		return (1);
	app->cub3d->sprite[0] = mlx_new_image_from_file(app->mlx,
			"textures/atrebois.jpg", NULL, NULL);
	app->cub3d->sprite[1] = mlx_new_image_from_file(app->mlx,
			"textures/sombronces.jpg", NULL, NULL);
	app->cub3d->sprite[2] = mlx_new_image_from_file(app->mlx,
			"textures/cravite.jpg", NULL, NULL);
	app->cub3d->sprite[3] = mlx_new_image_from_file(app->mlx,
			"textures/sablieres.jpg", NULL, NULL);
	app->cub3d->sprite[4] = mlx_new_image_from_file(app->mlx,
			"textures/leviathe.jpg", NULL, NULL);
	if (!app->cub3d->sprite[0] || !app->cub3d->sprite[1]
		|| !app->cub3d->sprite[2] || !app->cub3d->sprite[3]
		|| !app->cub3d->sprite[4])
		return (1);
	return (0);
}

suseconds_t	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
