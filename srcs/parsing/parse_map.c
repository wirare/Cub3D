/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:30:42 by joshua            #+#    #+#             */
/*   Updated: 2025/07/02 12:04:13 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

int	check_map_caracter(char **map, char *str)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			x = -1;
			while (str[++x])
			{
				if (map[i][j] == str[x])
					break ;
			}
			if (str[x] == '\0' && map[i][j] != '\0')
			{
				ft_printf("There is an invalid caracter in the map\n");
				return (1);
			}
		}
	}
	return (0);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	num_player;

	i = -1;
	num_player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == NORTH || map[i][j] == SOUTH || map[i][j] == EAST
				|| map[i][j] == WEST)
				num_player++;
		}
	}
	if (num_player != 1)
	{
		ft_printf("Not the correct number of player in the map\n");
		return (1);
	}
	return (0);
}

int	check_empty_line(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\n' && map[i + 1] && map[i + 1][0] == '\n')
			{
				ft_printf("There is an empty line in the map\n");
				return (1);
			}
		}
	}
	return (0);
}

int	check_separate_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] == '\n' || map[i][j] == '\0')
		{
			ft_printf("Invalid map\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_map(t_parsing parsing)
{
	if (check_player(parsing.map))
		return (1);
	if (check_map_caracter(parsing.map, " \n10DNSWE"))
		return (1);
	if (check_empty_line(parsing.map))
		return (1);
	return (0);
}
