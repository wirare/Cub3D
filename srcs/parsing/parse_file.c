/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:05:22 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 01:30:06 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_type.h"
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

int	check_element_map(t_parsing *parsing, int i, int j)
{
	return (*parsing->file && parsing->file[i][j] != P_FLOOR
		&& parsing->file[i][j] != P_WALL && parsing->file[i][j] != P_DOOR
		&& !ft_isspace(parsing->file[i][j]));
}

int	check_parsing_end(t_parsing *parsing, int i)
{
	int	j;

	while (parsing->file[i])
	{
		j = -1;
		while (parsing->file[i][++j])
		{
			if (check_element_map(parsing, i, j))
			{
				ft_printf("Error\nUnknow type for the map\n");
				return (1);
			}
			if (*parsing->file && (parsing->file[i][j] == P_FLOOR
				|| parsing->file[i][j] == P_WALL || parsing->file[i][j] == NORTH
				|| parsing->file[i][j] == SOUTH || parsing->file[i][j] == WEST
				|| parsing->file[i][j] == EAST
				|| parsing->file[i][j] == P_DOOR))
			{
				parsing->file += i;
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int	check_type(t_parsing *parsing, int *ret, int i, int j)
{
	if (check_component(NORTH_TEXTURE, parsing->file[i] + j))
		*ret = parse_texture("NO", parsing, parsing->file[i] + j + 2);
	else if (check_component(SOUTH_TEXTURE, parsing->file[i] + j))
		*ret = parse_texture("SO", parsing, parsing->file[i] + j + 2);
	else if (check_component(EAST_TEXTURE, parsing->file[i] + j))
		*ret = parse_texture("EA", parsing, parsing->file[i] + j + 2);
	else if (check_component(WEST_TEXTURE, parsing->file[i] + j))
		*ret = parse_texture("WE", parsing, parsing->file[i] + j + 2);
	else if (check_component(DOOR_, parsing->file[i] + j))
		*ret = parse_texture("DT", parsing, parsing->file[i] + j + 2);
	else if (check_component(FLOOR_COLOR, parsing->file[i] + j))
		*ret = parse_color(parsing, parsing->file[i] + j + 1, 'F');
	else if (check_component(CELLING_COLOR, parsing->file[i] + j))
		*ret = parse_color(parsing, parsing->file[i] + j + 1, 'C');
	else if (!*parsing->file[i] + j)
		return (0);
	else
		return (1);
	return (*ret);
}

int	parse_file(t_parsing *parsing)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (parsing->file[i])
	{
		if (*parsing->file[i] == '\0' || *parsing->file[i] == '\n'
			|| ft_strlen(parsing->file[i]) == 0)
		{
			i++;
			continue ;
		}
		j = 0;
		while (ft_isspace(parsing->file[i][j]))
			j++;
		if (check_type(parsing, &ret, i, j) == 1)
			break ;
		i++;
	}
	if (ret == 0)
		return (check_parsing_end(parsing, i));
	return (1);
}
