/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:16:52 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 22:59:53 by joshua           ###   ########.fr       */
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

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*void	init_pad_map(int *i, int *max_len, char **map, char ***copy)
{
	*i = 0;
	*max_len = found_longest_line(map);
	*copy = malloc((array_len(map)) * sizeof(char *));
}*/
