/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tas.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:11:08 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/01 21:15:10 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <SDL2/SDL_scancode.h>
#include <app.h>
#include <stdio.h>
#include <regex.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lib/libft/headers/gnl.h"

#define PATTERN "^[0-9]+, [A-Z]+\n$"

int	convert_char_to_input(char c)
{
	if (c == 'A')
		return (SDL_SCANCODE_A);
	if (c == 'S')
		return (SDL_SCANCODE_S);
	if (c == 'D')
		return (SDL_SCANCODE_D);
	if (c == 'W')
		return (SDL_SCANCODE_W);
	if (c == 'L')
		return (SDL_SCANCODE_LEFT);
	if (c == 'R')
		return (SDL_SCANCODE_RIGHT);
	if (c == 'O')
		return (SDL_SCANCODE_O);
	return (-1);
}

void	convert_tas_file(int fd, int ***tas_inputs, int nb_lines)
{
	char	*line;
	int		line_index;
	int		num;
	int		input_count;
	int		i;
	int		j;
	int		*input_array;
	int		input_index;

	*tas_inputs = malloc((nb_lines + 1) * sizeof(int *));
	if (!*tas_inputs)
		return ;
	line_index = 0;
	line = get_next_line(fd);
	while (line_index < nb_lines && line)
	{
		i = 0;
		num = 0;
		while (line[i] != ',')
		{
			if (line[i] - 0x30 <= 9)
				num = num * 10 + (line[i] - '0');
			i++;
		}
		i++;
		j = i;
		input_count = 0;
		while (line[j])
		{
			if (line[j] != ' ' && line[j] != '\n')
				input_count++;
			j++;
		}
		input_array = malloc((input_count + 2) * sizeof(int));
		input_array[0] = num;
		input_index = 1;
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '\n')
				input_array[input_index++] = convert_char_to_input(line[i]);
			i++;
		}
		input_array[input_index] = -1;
		(*tas_inputs)[line_index++] = input_array;
		free(line);
		line = get_next_line(fd);
	}
	(*tas_inputs)[line_index] = NULL;
}

int	read_tas_file(int ***tas_inputs)
{
	char	*line;
	int		fd;
	int		lineno;
	bool	invalid;
	regex_t	regex;

	fd = open("inputs.tas", O_RDONLY);
	if (fd == -1)
		return (printf("File open failed\n"), 1);
	if (regcomp(&regex, PATTERN, REG_EXTENDED))
		return (close(fd), printf("Regex compilation failed\n"), 1);
	invalid = false;
	lineno = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (regexec(&regex, line, 0, NULL, 0) != 0)
		{
			printf("Line %d: ❌ Invalid format --> \"%s\"\n", lineno, line);
			invalid = true;
		}
		free(line);
		lineno++;
		line = get_next_line(fd);
	}
	close(fd);
	regfree(&regex);
	if (invalid)
		return (1);
	fd = open("inputs.tas", O_RDONLY);
	if (fd == -1)
		return (printf("File reopen failed\n"), 1);
	convert_tas_file(fd, tas_inputs, lineno - 1);
	close(fd);
	return (0);
}
