/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:16:10 by jodougla          #+#    #+#             */
/*   Updated: 2025/05/14 11:29:52 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

bool	check_file_name(char *file_name)
{
	int				fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
		{
			print_error(file_name, "Bad permission");
			exit (1);
		}
		else if (errno == ENOENT)
		{
			print_error(file_name, "No such file or directory");
			exit (2);
		}
		else
		{
			print_error(file_name, "open cpt");
			exit (3);
		}
	}

	return (0);
}
