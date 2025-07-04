/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 15:02:49 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	int			i;
	int			tas;

	tas = check_argc(argc, argv);
	set_parsing(&parsing);
	check_file_name(argv[1], &parsing);
	if (parse_file(&parsing) == 0)
	{
		if (parsing.floor == NULL || parsing.celling == NULL
			|| parsing.ea.path == NULL || parsing.we.path == NULL
			|| parsing.no.path == NULL || parsing.so.path == NULL)
		{
			ft_printf("Missing component in the map\n");
			free_parsing(parsing);
			return (1);
		}
		parsing.map = parsing.file;
		if (parse_map(parsing) == 0)
		{
			i = -1;
			while (parsing.map[++i])
			{
				parsing.map[i] = ft_strtrim(parsing.map[i], "\n");
				push(parsing.map[i]);
			}
			if (prep_floodfill(parsing.map) == 0)
				prep_exec(parsing, tas);
		}
		else
			parsing.map = NULL;
	}
	free_parsing(parsing);
}
