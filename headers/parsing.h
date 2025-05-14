/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:57:07 by jodougla          #+#    #+#             */
/*   Updated: 2025/05/14 11:28:21 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>

typedef enum e_file_error
{
	WRONG_EXTENSION,
	NO_PERM,
	WRONG_PATH,
}			t_file_error;

bool	check_file_name(char *file_name);
void	print_error(char *error, char *error_msg);

#endif
