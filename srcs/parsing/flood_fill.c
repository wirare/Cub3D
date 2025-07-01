/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:59:53 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 23:29:19 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_str.h"
#include <parsing.h>

#include <stdlib.h>
#include <string.h>

int	found_longest_line(char **str)
{
	int	i = 0;
	int	max_len = 0;
	while (str[i])
	{
		int len = strlen(str[i]);
		if (max_len < len)
			max_len = len;
		i++;
	}
	return (max_len);
}

char	**pad_map(char **map, int height, int max_len)
{
	char **copy = malloc((height + 1) * sizeof(char *));
	for (int i = 0; i < height; i++)
	{
		copy[i] = malloc(max_len + 1);
		int j = 0;
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		while (j < max_len)
			copy[i][j++] = ' ';
		copy[i][j] = '\0';
	}
	copy[height] = NULL;
	return copy;
}

int	is_in_bounds(int x, int y, int height, int max_len)
{
	if (y < 0 || y >= height)
		return 0;
	if (x < 0 || x >= max_len)
		return 0;
	return 1;
}

int	flood_fill(char **map, int x, int y, int height, int max_len)
{
	if (!is_in_bounds(x, y, height, max_len))
		return 0;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return 1;
	if (map[y][x] == ' ')
		return 0;
	map[y][x] = 'F';
	return (flood_fill(map, x+1, y, height, max_len)
		&& flood_fill(map, x-1, y, height, max_len)
		&& flood_fill(map, x, y+1, height, max_len)
		&& flood_fill(map, x, y-1, height, max_len));
}

int	check_map_closed(char **map, int player_x, int player_y)
{
	int height = 0;
	while (map[height])
		height++;
	int max_len = found_longest_line(map);
	char **padded = pad_map(map, height, max_len);
	int result = flood_fill(padded, player_x, player_y, height, max_len);
	// free padded map...
	for (int i = 0; i < height; i++)
		free(padded[i]);
	free(padded);
	return result;
}

int	prep_flood_fill(char **map)
{
	int	player_x;
	int	player_y;

	get_player_pos(map, &player_x, &player_y);
	if (!check_map_closed(map, player_x, player_y))
	{
		ft_printf("map ouverte\n");
		return (1);
	}
	return (0);
}

/*int	found_longest_line(char **str)
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
	return (max_len);
}

char	**pad_map(char **map)
{
	char	**copy;
	int		i;
	int		j;
	int		max_len;

	init_pad_map(&i, &max_len, map, &copy);
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
			copy[i][j++] = 'P';
		copy[i][j] = '\0';
		i++;
	}
	return (copy);
}

int	is_in_bounds(char **map, int x, int y, int heigth)
{
	if (y < 0 || y >= heigth)
		return (0);
	if (!map[y])
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
//	if (y < 0 || y >= heigth)
//		return (0);
//	if (!map[y])
//		return (0);
//	len = ft_strlen(map[y]);
//	if (x < 0 || x >= len)
//		return (0);
//	return (1);
}

int	flood_fill(char **map, int x, int y, int heigth)
{
	if (!is_in_bounds(map, x, y, heigth))
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	if (map[y][x] == ' ')
		return (0);
	map[y][x] = 'F';
	return (flood_fill(map, x + 1, y, heigth)
		&& flood_fill(map, x - 1, y, heigth)
		&& flood_fill(map, x, y + 1, heigth)
		&& flood_fill(map, x, y - 1, heigth));
}

int	prep_flood_fill(char **map)
{
	char	**copy_map;
	int		heigth;
	int		i;
	int		player_x;
	int		player_y;

	i = -1;
	get_player_pos(map, &player_x, &player_y);
	while (map[++i])
		map[i] = ft_strtrim(map[i], "\n");
	copy_map = pad_map(map);
	heigth = array_len(map);
	if (!flood_fill(copy_map, player_x, player_y, heigth))
	{
		ft_printf("Map not close\n");
		return (1);
	}
//	i = -1;
//	while (++i < heigth)
//		free(copy_map[i]);
//	free(copy_map);
//	i = -1;
//	while (map[++i])
//		free(map[i]);
	return (0);
}*/
