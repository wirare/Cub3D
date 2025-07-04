/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:53:03 by joshua            #+#    #+#             */
/*   Updated: 2025/07/05 01:28:30 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_type.h"
#include <parsing.h>

void	set_celling(t_parsing *parsing, int r, int g, int b)
{
	parsing->celling = malloc (sizeof(t_color));
	parsing->celling->r = r;
	parsing->celling->g = g;
	parsing->celling->b = b;
}

void	set_floor(t_parsing *parsing, int r, int g, int b)
{
	parsing->floor = malloc (sizeof(t_color));
	parsing->floor->r = r;
	parsing->floor->g = g;
	parsing->floor->b = b;
}

int	parse_one_color(char **line, int *color, int *ret)
{
	if (!ft_isdigit(**line))
	{
		ft_printf("Error\nOne or more invalid\
caracter in a color componenet\n");
		*ret = 1;
		return (1);
	}
	*color = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	*line = skip_space(*line);
	return (0);
}

int	get_collor(char *line, int *r, int *g, int *b)
{
	int	ret;

	ret = 0;
	if (parse_one_color(&line, r, &ret) || *line != ',')
		return (print_error("Error\nIn one of the color component", ret));
	line++;
	line = skip_space(line);
	if (parse_one_color(&line, g, &ret) || *line != ',')
		return (print_error("Error\nIn one of the color component", ret));
	line++;
	line = skip_space(line);
	if (parse_one_color(&line, b, &ret))
		return (print_error("Error\nIn one of the color component", ret));
	if (*line != '\n' && *line != '\0')
	{
		ft_printf("Error\nInvalid caracter in one of the color component\n");
		return (1);
	}
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
	{
		ft_printf("Error\nOne of the rgb\
component is not bet ween 0 and 255\n");
		return (1);
	}
	return (0);
}

int	parse_color(t_parsing *parsing, char *line, char type)
{
	int	r;
	int	g;
	int	b;

	line = skip_space(line);
	if ((type == 'C' && parsing->celling != NULL)
		|| (type == 'F' && parsing->floor != NULL))
	{
		ft_printf("Error\n%c is set multiple times\n", type);
		return (1);
	}
	if (get_collor(line, &r, &g, &b))
		return (1);
	if (type == 'C')
		set_celling(parsing, r, g, b);
	else
		set_floor(parsing, r, g, b);
	return (0);
}
