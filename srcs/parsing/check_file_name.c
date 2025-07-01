/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:16:10 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/01 09:36:41 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

void	get_file(char *file_name, t_parsing *parsing, int fd)
{
	int		size;
	int		i;
	char	*line;

	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		size++;
		free(line);
	}
	parsing->file = malloc(sizeof(char *) * (size + 1));
	push(parsing->file);
	close(fd);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		parsing->file[i] = line;
		push(parsing->file[i++]);
		if (line == NULL)
			break ;
	}
	close(fd);
}

void	print(char *file_name)
{
	if (errno == EACCES)
	{
		ft_printf("%sCub3D :%s :No permission \
for this file\n%s", RED, file_name, RESET);
		exit (1);
	}
	else if (errno == ENOENT)
	{
		ft_printf("%sCub3D :%s :No such a file\n%s", RED, file_name, RESET);
		exit (2);
	}
	else
	{
		ft_printf("%sCub3D :Open failed\n%s", RED, RESET);
		exit (3);
	}
}

void	check_file_name(char *file_name, t_parsing *parsing)
{
	int	fd;
	int	check_dir;
	int	len_name;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print(file_name);
	len_name = ft_strlen(file_name);
	check_dir = open(file_name, O_DIRECTORY);
	if (check_dir != -1)
	{
		close(check_dir);
		close(fd);
		ft_printf("%sCub3D :%s is a directory\n%s", RED, file_name, RESET);
		exit (4);
	}
	if (ft_strncmp(file_name + (len_name - 4), ".cub", 5) != 0)
	{
		close(fd);
		ft_printf("%sCub3D :this file is \
missing the \".cub\" extension\n%s", RED, RESET);
		exit (5);
	}
	get_file(file_name, parsing, fd);
}
