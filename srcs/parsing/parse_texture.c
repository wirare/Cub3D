/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:33:16 by jodougla          #+#    #+#             */
/*   Updated: 2025/06/13 13:35:01 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

void	select_texture(char *texture_to_parse, char *line, t_parsing *parsing)
{
	if (ft_strncmp(texture_to_parse, "NO", 3) == 0)
	{
		parsing->north_texture = 1;
		parsing->no.path = line;
	}
	else if (ft_strncmp(texture_to_parse, "SO", 3) == 0)
	{
		parsing->south_texture = 1;
		parsing->so.path = line;
	}
	else if (ft_strncmp(texture_to_parse, "EA", 3) == 0)
	{
		parsing->east_texture = 1;
		parsing->ea.path = line;
	}
	else if (ft_strncmp(texture_to_parse, "WE", 3) == 0)
	{
		parsing->west_texture = 1;
		parsing->we.path = line;
	}
}

void	parse_texture(char *texture_to_parse, t_parsing *parsing, char *line)
{
	int		fd;
	char	*line_to_open;

	while (ft_isspace(*line))
		line++;
	line_to_open = ft_substr(line, 0, ft_strlen(line) - 1);
	fd = open(line_to_open, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("can't open this file :%s\n", line_to_open);
		parsing->error = 1;
		free(line_to_open);
	}
	else
	{
		close(fd);
		select_texture(texture_to_parse, line_to_open, parsing);
	}
}
