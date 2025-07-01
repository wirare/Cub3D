/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <joshua@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:53:03 by joshua            #+#    #+#             */
/*   Updated: 2025/06/28 19:24:45 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	parse_one_color(char **line, int *color)
{
	if (!ft_isdigit(**line))
	{
		ft_printf("One or more invalid caracter in a color componenet\n");
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
	if (parse_one_color(&line, r) != 0 || *line != ',')
		return (1);
	line++;
	line = skip_space(line);
	if (parse_one_color(&line, g) || *line != ',')
		return (1);
	line++;
	line = skip_space(line);
	if (parse_one_color(&line, b))
		return (1);
	line = skip_space(line);
	if (*line != '\0' && *line != '\n')
	{
		ft_printf("One or more invalid caracter in a color componenet\n");
		return (1);
	}
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
	{
		ft_printf("one of the color is not between 0 and 255\n");
		return (1);
	}
	return (0);
}

int parse_color(t_parsing *parsing, char *line, char type)
{
	int	r;
	int	g;
	int	b;

	line = skip_space(line);
	if ((type == 'C' && parsing->celling != NULL)
		|| (type == 'F' && parsing->floor != NULL))
	{
		ft_printf("%c is set multiple times\n", type);
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
