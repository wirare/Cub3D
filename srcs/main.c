/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/05/14 11:09:12 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		ft_printf("Error :Not the right number of argument, put two argument, \
exemple :./Cub3d path_to_the_map\n");
		exit (1);
	}
	check_file_name(argv[1]);
}
