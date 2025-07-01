/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:16:52 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 14:38:51 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

char	*skip_space(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (line + i);
}

void	flood_fill_init(t_flood_fill *flood_fill)
{
	flood_fill->i = 0;
	flood_fill->num_rec = 0;
	flood_fill->max_stack_reached = 0;
	flood_fill->x = -1;
	flood_fill->y = -1;
	flood_fill->error = 0;
}

int	ft_str_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (*(arr + i) != NULL)
		i++;
	return (i);
}

void	get_player_pos(char **map, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == NORTH || map[i][j] == SOUTH || map[i][j] == EAST
				|| map[i][j] == WEST)
			{
				*player_x = j;
				*player_y = i;
				return ;
			}
		}
	}
}
