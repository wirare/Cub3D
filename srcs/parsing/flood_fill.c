/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:59:53 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 19:38:06 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_str.h"
#include <parsing.h>

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	found_longest_line(char **str)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	while (str[i])
	{
		if (max_len < (int)ft_strlen(str[i]))
			max_len = ft_strlen(str[i]);
		i++;
	}
	return(max_len);
}

char	**pad_map(char **map)
{
	char	**copy;
	int		i;
	int		j;
	int		max_len;

	i = 0;
	max_len = found_longest_line(map);
	copy = malloc((array_len(map)) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		j = 0;
		copy[i] = malloc((max_len + 1) * sizeof(char));
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				copy[i][j] = 'P';
			else
				copy[i][j] = map[i][j];
			j++;
		}
		while (j < max_len)
		{
			copy[i][j] = 'P';
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	return (copy);
}

int	is_in_bounds(char **map, int x, int y, int heigth)
{
	int	len;

	if (y < 0 || y >= heigth)
		return (0);
	if (!map[y])
		return (0);
	len = ft_strlen(map[y]);
	if (x < 0 || x >= len)
		return (0);
	return (1);
}

int	flood_fill(char **map, int x, int y, int heigth)
{
	if (!is_in_bounds(map, x, y, heigth))
		return (0);
//	if (map[y][x] != FLOOR && map[y][x] != NORTH && map[y][x] != SOUTH 
//		&& map[y][x] != EAST && map[y][x] != WEST && map[y][x] != DOOR && map[y][x] != 'P')
//		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	if (map[y][x] == 'P')
		return (0);
	map[y][x] = 'F';
	for (int i = 0; i < heigth; i++)
		ft_printf("%s\n", map[i]);
	ft_printf("\n\n\n\n");
	if (!flood_fill(map, x + 1, y, heigth))
		return (0);
	if (!flood_fill(map, x - 1, y, heigth))
		return (0);
	if (!flood_fill(map, x, y + 1, heigth))
		return (0);
	if (!flood_fill(map, x, y - 1, heigth))
		return (0);
//	return (flood_fill(map, x + 1, y, heigth)
//	&& flood_fill(map, x - 1, y, heigth)
//	&& flood_fill(map, x, y + 1, heigth)
//	&& flood_fill(map, x, y - 1, heigth));
	return (1);
}

int	prep_flood_fill(char **map)
{
	char	**copy_map;
	int		heigth;
	int		i;
	int		player_x;
	int		player_y;

	i = 0;
	get_player_pos(map, &player_x, &player_y);
	while (map[i])
	{
		map[i] = ft_strtrim(map[i], "\n");
		i++;
	}
	copy_map = pad_map(map);
	heigth = array_len(map);
	for (int i = 0; i < heigth; i++)
		ft_printf("%s\n", copy_map[i]);
	if (!flood_fill(copy_map, player_x, player_y, heigth))
	{
		ft_printf("Map not close\n");
		return (1);
	}
	i = -1;
	while (++i < heigth)
		free(copy_map[i]);
	free(copy_map);
	i = -1;
	while (map[++i])
		free(map[i]);
	return (0);
}
