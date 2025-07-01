/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:10:07 by joshua            #+#    #+#             */
/*   Updated: 2025/07/01 14:36:48 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

int	recursion_management(t_flood_fill *flood_fill_man,
								int *x, int *y, char **map)
{
	if (flood_fill_man->max_stack_reached == 1)
		return (-1);
	if (flood_fill_man->i == 1000)
	{
		flood_fill_man->max_stack_reached = 1;
		flood_fill_man->i = 0;
		return (-1);
	}
	if (flood_fill_man->i == 0 && flood_fill_man->num_rec != 0)
	{
		*x = flood_fill_man->x;
		*y = flood_fill_man->y;
		map[*y][*x] = '0';
	}
	flood_fill_man->num_rec++;
	flood_fill_man->i++;
	return (0);
}

int	is_wall(int x, int y, char **map)
{
	if (map[x][y] == '1' || map[x][y] == 'D')
		return (1);
	return (0);
}

static int	flood_fill(int x, int y, char **map,
						t_flood_fill *flood_fill_man)
{
	if (recursion_management(flood_fill_man, &x, &y, map))
		return (-1);
	if (x < 0 || y < 0 || y >= ft_str_arr_len(map)
		|| x >= (int)ft_strlen(map[y]) || ft_isspace(map[y][x]) != 0)
	{
		flood_fill_man->error = 1;
		return (1);
	}
	else if (is_wall(y, x, map))
		return (0);
	else if (map[y][x] == '0')
	{
		flood_fill_man->x = x;
		flood_fill_man->y = y;
	}
	map[y][x] = '1';
	return (flood_fill(x + 1, y, map, flood_fill_man)
		+ flood_fill(x - 1, y, map, flood_fill_man)
		+ flood_fill(x, y + 1, map, flood_fill_man)
		+ flood_fill(x, y - 1, map, flood_fill_man));
}

static int	managed_flood_fill(int player_x, int player_y, char **map,
						t_flood_fill *rec_man)
{
	int	ret;

	ret = -1;
	while (ret != 0)
	{
		ret = flood_fill(player_x, player_y, map, rec_man);
		rec_man->max_stack_reached = 0;
		if (rec_man->error == 1)
			break ;
	}
	return (ret);
}

int	prep_flood_fill(char **map)
{
	int				player_x;
	int				player_y;
	t_flood_fill	flood_fill_man;

	get_player_pos(map, &player_x, &player_y);
	flood_fill_init(&flood_fill_man);
	managed_flood_fill(player_x, player_y, map, &flood_fill_man);
	if (flood_fill_man.error == 1)
	{
		ft_printf("Invalid map\n");
		return (1);
	}
	return (0);
}
