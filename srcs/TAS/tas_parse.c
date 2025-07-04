/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tas_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:22:27 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:54:22 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <regex.h>
#include <libft.h>
#include <fcntl.h>

void	check_format(int fd, int *lineno)
{
	char	*line;
	bool	invalid;
	regex_t	regex;

	if (regcomp(&regex, PATTERN, REG_EXTENDED))
		return (close(fd), printf("Regex compilation failed\n"), (void)0);
	invalid = false;
	*lineno = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (regexec(&regex, line, 0, NULL, 0) != 0)
		{
			printf("Line %d: ❌ Invalid format --> \"%s\"\n", *lineno, line);
			invalid = true;
		}
		free(line);
		(*lineno)++;
		line = get_next_line(fd);
	}
	close(fd);
	regfree(&regex);
	if (invalid)
		*lineno = 0;
	else
		(*lineno)--;
}

int	read_tas_file(int ***tas_inputs)
{
	int		fd;
	int		lineno;

	fd = open("inputs.tas", O_RDONLY);
	if (fd == -1)
		return (printf("File open failed\n"), 1);
	lineno = 0;
	check_format(fd, &lineno);
	fd = open("inputs.tas", O_RDONLY);
	if (fd == -1)
		return (printf("File reopen failed\n"), 1);
	if (lineno != 0)
		convert_tas_file(fd, tas_inputs, lineno - 1);
	close(fd);
	return (lineno == 0);
}
