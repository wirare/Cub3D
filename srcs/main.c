/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/02 17:49:12 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <parsing.h>

void	prep_exec(t_parsing parsing)
{
	t_app	app;

	app.mlx = mlx_init();
	set_texture(&parsing, app);
	if (!parsing.ea.img || !parsing.we.img
		|| !parsing.no.img || !parsing.so.img)
	{
		ft_printf("error\n");
		if (parsing.ea.img)
			mlx_destroy_image(app.mlx, parsing.ea.img);
		if (parsing.we.img)
			mlx_destroy_image(app.mlx, parsing.we.img);
		if (parsing.so.img)
			mlx_destroy_image(app.mlx, parsing.no.img);
		if (parsing.no.img)
			mlx_destroy_image(app.mlx, parsing.so.img);
		return ;
	}
	app.cub3d->ground_color = (mlx_color){.r = parsing.floor->r,
		.g = parsing.floor->g, .b = parsing.floor->b, .a = 0xFF};
	app.cub3d->sky_color = (mlx_color){.r = parsing.celling->r,
		.g = parsing.celling->g, .b = parsing.celling->b, .a = 0xFF};
	app.cub3d->map_height = len_array(parsing.map);
	app.cub3d->map_width = max_line_len(parsing.map);
}

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	int			i;

	check_argc(argc);
	set_parsing(&parsing);
	check_file_name(argv[1], &parsing);
	if (parse_file(&parsing) == 0)
	{
		parsing.map = parsing.file;
		if (parse_map(parsing) == 0)
		{
			i = -1;
			while (parsing.map[++i])
				parsing.map[i] = ft_strtrim(parsing.map[i], "\n");
			if (prep_floodfill(parsing.map) == 0)
				prep_exec(parsing);
		}
		else
			parsing.map = NULL;
	}
	free_parsing(parsing);
}
