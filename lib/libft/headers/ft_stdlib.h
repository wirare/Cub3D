/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:07:58 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:19:56 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include "ft_type.h"
# include "ft_string.h"
# include <stdlib.h>
# include <math.h>

float	ft_atof(char *str);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmeb, size_t size);
char	*ft_strdup(const char *s);

#endif
