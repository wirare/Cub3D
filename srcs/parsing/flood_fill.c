/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:59:53 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 19:58:08 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_str.h"
#include <parsing.h>

/*int	array_len(char **str)
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
}*/

#include <stdlib.h>
#include <string.h>

int array_len(char **map)
{
	int i = 0;
	while (map && map[i])
		i++;
	return i;
}

int found_longest_line(char **map)
{
	int i = 0, max = 0;
	while (map && map[i])
	{
		int len = strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return max;
}

/**
 * Prend une map `char **map` et renvoie une nouvelle map padée
 * avec un cadre de 'P' tout autour.
 * - La map d'origine N'EST PAS modifiée ni libérée.
 * - Il faut penser à free la map retournée quand tu as fini.
 */
char	**pad_map(char **map)
{
	int orig_height = array_len(map);
	int max_len = found_longest_line(map);
	int new_height = orig_height + 2;
	int new_width = max_len + 2;
	char **copy = malloc(sizeof(char *) * (new_height + 1));
	int i, j;

	// Ligne du haut (full padding)
	copy[0] = malloc(new_width + 1);
	for (j = 0; j < new_width; j++)
		copy[0][j] = 'P';
	copy[0][j] = '\0';

	// Lignes du centre (chaque ligne de la map d'origine)
	for (i = 0; i < orig_height; i++)
	{
		copy[i+1] = malloc(new_width + 1);
		copy[i+1][0] = 'P';
		for (j = 0; j < max_len; j++)
			copy[i+1][j+1] = (map[i][j] && map[i][j] != ' ') ? map[i][j] : 'P';
		copy[i+1][j+1] = 'P';
		copy[i+1][j+2] = '\0';
	}

	// Ligne du bas (full padding)
	copy[new_height-1] = malloc(new_width + 1);
	for (j = 0; j < new_width; j++)
		copy[new_height-1][j] = 'P';
	copy[new_height-1][j] = '\0';

	copy[new_height] = NULL;
	return copy;
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
//	for (int i = 0; i < heigth; i++)
//		ft_printf("%s\n", map[i]);
//	ft_printf("\n\n\n\n");
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
	for (int i = 0; i < heigth + 2; i++)
		ft_printf("%s\n", copy_map[i]);
	if (!flood_fill(copy_map, player_x + 1, player_y + 1, heigth + 2))
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
