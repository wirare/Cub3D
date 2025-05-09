/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:15:20 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 14:39:22 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_TYPE_H
# define FT_TYPE_H

# include <stdbool.h>

bool	ft_isalnum(int c);
bool	ft_isalpha(int c);
bool	ft_isascii(int c);
bool	ft_isdigit(int c);
bool	ft_isprint(int c);
bool	ft_issign(int c);
bool	ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
