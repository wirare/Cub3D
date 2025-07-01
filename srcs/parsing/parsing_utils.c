/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:16:52 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 18:45:37 by jodougla         ###   ########.fr       */
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
