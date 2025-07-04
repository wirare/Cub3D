/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tas_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:22:27 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/05 01:24:41 by ellanglo         ###   ########.fr       */
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
		return (close(fd), printf("Error\nRegex compilation failed\n"), (void)0);
	invalid = false;
	*lineno = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (regexec(&regex, line, 0, NULL, 0) != 0)
		{
			printf("Error\nLine %d: ❌ Invalid format --> \"%s\"\n", *lineno, line);
			invalid = true;
		}
		free(line);
		(*lineno)++;
		line = get_next_line(fd);
	}
	close(fd);
	regfree(&regex);
	(*lineno)--;
	if (invalid)
		*lineno = 0;
}

int	read_tas_file(int ***tas_inputs)
{
	int		fd;
	int		lineno;

	fd = open("inputs.tas", O_RDONLY);
	if (fd == -1)
		return (printf("Error\nFile open failed\n"), 1);
	lineno = 0;
	check_format(fd, &lineno);
	fd = open("inputs.tas", O_RDONLY);
	if (fd == -1)
		return (printf("Error\nFile reopen failed\n"), 1);
	if (lineno != 0)
		convert_tas_file(fd, tas_inputs, lineno);
	close(fd);
	return (lineno == 0);
}
