/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/01 12:37:53 by joshua           ###   ########.fr       */
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
	if (parsing.floor)
		free(parsing.floor);
	if (parsing.celling)
		free(parsing.celling);
}

int	main(int argc, char **argv)
{
	t_parsing	parsing;

	if (argc != 2)
	{
		ft_printf("Error :Not the right number of argument, put two argument, \
exemple :./Cub3d path_to_the_map\n");
		exit (1);
	}
	set_parsing(&parsing);
	check_file_name(argv[1], &parsing);
	if (parse_file(&parsing) == 0)
	{
		parsing.map = parsing.file;
		parsing.map = parsing.file;
		if (parse_map(parsing) == 0)
			prep_flood_fill(parsing.map);
	}
	free_parsing(parsing);
}
