/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/06/13 13:37:22 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

void	set_parsing(t_parsing *parsing)
{
	parsing->no.path = NULL;
	parsing->so.path = NULL;
	parsing->ea.path = NULL;
	parsing->we.path = NULL;
}

void	free_parsing(t_parsing parsing)
{
	ft_free(parsing.file);
	free(parsing.no.path);
	free(parsing.so.path);
	free(parsing.ea.path);
	free(parsing.we.path);
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
	parse_file(&parsing);
	free_parsing(parsing);
}
