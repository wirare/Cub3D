/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:05:22 by jodougla          #+#    #+#             */
/*   Updated: 2025/06/13 13:35:34 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

bool	check_component(char *component, char *line)
{
	int	len_component;
	int	len_line;

	len_component = ft_strlen(component);
	len_line = ft_strlen(line);
	if (ft_strncmp(line, component, len_component) == 0)
	{
		if (len_line > len_component && line[len_component] == ' ')
			return (1);
		return (0);
	}
	return (0);
}

void	parse_file(t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	while (parsing->file[i])
	{
		j = 0;
		while (ft_isspace(parsing->file[i][j]))
			j++;
		if (check_component(NORTH_TEXTURE, parsing->file[i] + j))
			parse_texture("NO", parsing, parsing->file[i] + j + 2);
		else if (check_component(SOUTH_TEXTURE, parsing->file[i] + j))
			parse_texture("SO", parsing, parsing->file[i] + j + 2);
		else if (check_component(EAST_TEXTURE, parsing->file[i] + j))
			parse_texture("EA", parsing, parsing->file[i] + j + 2);
		else if (check_component(WEST_TEXTURE, parsing->file[i] + j))
			parse_texture("WE", parsing, parsing->file[i] + j + 2);
		else if (check_component(FLOOR_COLOR, parsing->file[i] + j))
		{

		}
		else if (check_component(CELLING_COLOR, parsing->file[i] + j))
		{

		}
		i++;
	}
}
