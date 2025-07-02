/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:28:29 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/02 14:17:55 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

int	is_spawn(char c)
{
	return (c == NORTH || c == SOUTH || c == EAST || c == WEST);
}

char	**pad_map(char **map, int heigth, int width)
{
	char	**pad;
	int		i;
	int		j;

	i = -1;
	pad = malloc((heigth + 1) * sizeof(char *));
	while (++i < heigth)
	{
		pad[i] = malloc(width + 1 * sizeof(char));
		j = 0;
		while (map[i][j])
		{
			pad[i][j] = map[i][j];
			j++;
		}
		while (j < width)
			pad[i][j++] = ' ';
		pad[i][j] = '\0';
	}
	pad[heigth] = NULL;
	return (pad);
}

int	check_point(char **map, int x, int y, int size[2])
{
	static int	co_x[4] = {1, -1, 0, 0};
	static int	co_y[4] = {0, 0, 1, -1};
	int			co;
	int			heigth;
	int			width;

	heigth = size[0];
	width = size[1];
	if (map[y][x] == '0' || is_spawn(map[y][x]) || map[y][x] == 'D')
	{
		co = -1;
		while (++co < 4)
		{
			if (x + co_x[co] < 0 || y + co_y[co] < 0
				|| x + co_x[co] >= width || y + co_y[co] >= heigth)
				return (1);
			if (map[y + co_y[co]][x + co_x[co]] == ' ')
				return (1);
		}
	}
	return (0);
}

int	check_closed(char **map, int heigth, int width)
{
	int			y;
	int			x;
	int			size[2];

	size[0] = heigth;
	size[1] = width;
	y = -1;
	while (++y < heigth)
	{
		x = -1;
		while (++x < width)
		{
			if (check_point(map, x, y, size) == 1)
				return (1);
		}
	}
	return (0);
}

int	prep_floodfill(char **map)
{
	int		heigth;
	int		width;
	char	**pad;
	int		i;

	i = -1;
	heigth = 0;
	width = max_line_len(map);
	while (map[heigth])
		heigth++;
	pad = pad_map(map, heigth, width);
	if (check_closed(pad, heigth, width) == 1)
	{
		ft_printf("Map not closed\n");
		while (pad[++i])
			free(pad[i]);
		free(pad);
		return (1);
	}
	while (pad[++i])
		free(pad[i]);
	free(pad);
	return (0);
}
