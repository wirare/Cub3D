/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:28:55 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/05 00:39:42 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>
#include <fcntl.h>

int	check_element(t_parsing parsing)
{
	return (parsing.floor == NULL || parsing.celling == NULL
		|| parsing.ea.path == NULL || parsing.we.path == NULL
		|| parsing.no.path == NULL || parsing.so.path == NULL
		|| parsing.dt.path == NULL);
}

void	trim_map(t_parsing *parsing)
{
	int			i;

	i = -1;
	while (parsing->map[++i])
	{
		parsing->map[i] = ft_strtrim(parsing->map[i], "\n");
		push(parsing->map[i]);
	}
}

int	check_sprite2(void)
{
	int	fd;

	fd = open("textures/sablieres.jpg", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("One of the required sprites don't exist\n");
		return (1);
	}
	close(fd);
	fd = open("textures/leviathe.jpg", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("One of the required sprites don't exist\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	check_sprite(void)
{
	int	fd;

	fd = open("textures/atrebois.jpg", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("One of the required sprites don't exist\n");
		return (1);
	}
	close(fd);
	fd = open("textures/sombronces.jpg", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("One of the required sprites don't exist\n");
		return (1);
	}
	close(fd);
	fd = open("textures/cravite.jpg", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("One of the required sprites don't exist\n");
		return (1);
	}
	close(fd);
	return (check_sprite2());
}

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	int			tas;

	if (check_sprite())
		return (1);
	tas = check_argc(argc, argv);
	set_parsing(&parsing);
	check_file_name(argv[1], &parsing);
	if (parse_file(&parsing) == 0)
	{
		if (check_element(parsing))
			error_file(parsing);
		parsing.map = parsing.file;
		if (parse_map(parsing) == 0)
		{
			trim_map(&parsing);
			if (prep_floodfill(parsing.map) == 0)
				prep_exec(parsing, tas);
		}
		else
			parsing.map = NULL;
	}
	free_parsing(parsing);
}
