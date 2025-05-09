/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:20:01 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:44:01 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STR_H
# define FT_STR_H

# include "ft_stdlib.h"
# include "ft_string.h"
# include <stdlib.h>
# include <stdarg.h>

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_vargs(int n_arg, ...);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
