/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:03:31 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:57:05 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <gnl.h>

char	*loop(char *line, int fd, char *backlash, int bytes_read)
{
	static char	buff[1024][BUFFER_SIZE + 1] = {0};

	bytes_read = 1;
	line = NULL;
	while (1)
	{
		if (!*buff[fd])
			bytes_read = read(fd, buff[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		backlash = ft_strchr(buff[fd], '\n');
		if (!backlash)
		{
			line = ft_strnjoin(line, buff[fd], BUFFER_SIZE + 1);
			ft_memset(buff[fd], 0, BUFFER_SIZE + 1);
			continue ;
		}
		line = ft_strnjoin(line, buff[fd], backlash - buff[fd] + 1);
		ft_memmove(buff[fd], backlash + 1, BUFFER_SIZE + 1);
		break ;
	}
	if (bytes_read == -1)
		ft_memset(buff[fd], 0, BUFFER_SIZE + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*backlash;
	int		bytes_read;

	bytes_read = 0;
	backlash = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = loop(line, fd, backlash, bytes_read);
	return (line);
}
