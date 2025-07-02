/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:38:20 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/02 17:40:27 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

void	set_parsing(t_parsing *parsing)
{
	parsing->no.path = NULL;
	parsing->so.path = NULL;
	parsing->ea.path = NULL;
	parsing->we.path = NULL;
	parsing->floor = NULL;
	parsing->celling = NULL;
	parsing->map = NULL;
}

void	free_parsing(t_parsing parsing)
{
	int	i;

	if (parsing.no.path)
		free(parsing.no.path);
	if (parsing.so.path)
		free(parsing.so.path);
	if (parsing.ea.path)
		free(parsing.ea.path);
	if (parsing.we.path)
		free(parsing.we.path);
	if (parsing.floor)
		free(parsing.floor);
	if (parsing.celling)
		free(parsing.celling);
	i = -1;
	if (parsing.map != NULL)
	{
		while (parsing.map[++i])
			free(parsing.map[i]);
	}
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error :Not the right number of argument, put two argument, \
exemple :./Cub3d path_to_the_map\n");
		exit (1);
	}
}

void	set_texture(t_parsing *parsing, t_app app)
{
	parsing->ea.img = mlx_new_image_from_file(app.mlx,
			parsing->ea.path, &parsing->ea.width, &parsing->ea.heigth);
	parsing->we.img = mlx_new_image_from_file(app.mlx,
			parsing->we.path, &parsing->we.width, &parsing->we.heigth);
	parsing->no.img = mlx_new_image_from_file(app.mlx,
			parsing->no.path, &parsing->no.width, &parsing->no.heigth);
	parsing->so.img = mlx_new_image_from_file(app.mlx,
			parsing->so.path, &parsing->so.width, &parsing->so.heigth);
}
