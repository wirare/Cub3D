/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:55:55 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 16:02:32 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GNL_H
# define GNL_H

# include "ft_string.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strnjoin(char *s1, char *s2, int len);

#endif
