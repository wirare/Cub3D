/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tas_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:11:08 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:26:46 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <SDL2/SDL_scancode.h>
#include <app.h>
#include <regex.h>
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>

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

static int	get_input_count(char *line, int i)
{
	int	count;

	count = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

static int	get_first_number(char *line, int *i)
{
	int	num;

	num = 0;
	while (line[*i] && line[*i] != ',')
	{
		if (line[*i] >= '0' && line[*i] <= '9')
			num = num * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (line[*i] == ',')
		(*i)++;
	return (num);
}

static int	*parse_inputs(char *line, int num)
{
	int	i;
	int	input_count;
	int	input_index;
	int	*input_array;

	i = 0;
	num = get_first_number(line, &i);
	input_count = get_input_count(line, i);
	input_array = malloc((input_count + 2) * sizeof(int));
	if (!input_array)
		return (NULL);
	input_array[0] = num;
	input_index = 1;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			input_array[input_index++] = convert_char_to_input(line[i]);
		i++;
	}
	input_array[input_index] = -1;
	return (input_array);
}

void	convert_tas_file(int fd, int ***tas_inputs, int nb_lines)
{
	int		line_index;
	char	*line;
	int		*input_array;

	*tas_inputs = malloc((nb_lines + 1) * sizeof(int *));
	if (!*tas_inputs)
		return ;
	line_index = 0;
	line = get_next_line(fd);
	while (line_index < nb_lines && line)
	{
		input_array = parse_inputs(line, 0);
		(*tas_inputs)[line_index++] = input_array;
		free(line);
		line = get_next_line(fd);
	}
	(*tas_inputs)[line_index] = NULL;
}
