/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:33:16 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 01:26:36 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

int	select_texture(char *texture_to_parse, char *line, t_parsing *parsing)
{
	if (ft_strncmp(texture_to_parse, "NO", 3) == 0 && parsing->no.path == NULL)
		parsing->no.path = ft_strdup(line);
	else if (ft_strncmp(texture_to_parse, "SO", 3) == 0
		&& parsing->so.path == NULL)
		parsing->so.path = ft_strdup(line);
	else if (ft_strncmp(texture_to_parse, "EA", 3) == 0
		&& parsing->ea.path == NULL)
		parsing->ea.path = ft_strdup(line);
	else if (ft_strncmp(texture_to_parse, "WE", 3) == 0
		&& parsing->we.path == NULL)
		parsing->we.path = ft_strdup(line);
	else if (ft_strncmp(texture_to_parse, "DT", 3) == 0
		&& parsing->dt.path == NULL)
		parsing->dt.path = ft_strdup(line);
	else
	{
		ft_printf("Error\nThis texture is set multiple \
times : %s\n", texture_to_parse);
		return (1);
	}
	return (0);
}

int	parse_texture(char *texture_to_parse, t_parsing *parsing, char *line)
{
	int		fd;
	char	*line_to_open;
	int		err;

	err = 0;
	while (ft_isspace(*line))
		line++;
	line_to_open = ft_substr(line, 0, ft_strlen(line) - 1);
	fd = open(line_to_open, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\ncan't open this file :%s\n", line_to_open);
		parsing->error = 1;
		free(line_to_open);
		return (1);
	}
	else
	{
		close(fd);
		err = select_texture(texture_to_parse, line_to_open, parsing);
		free(line_to_open);
		return (err);
	}
}
