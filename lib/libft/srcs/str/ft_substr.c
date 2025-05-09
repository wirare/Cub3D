/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:36:20 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:21:42 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_str.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n_str;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	n_str = ft_calloc (len + 1, sizeof(char));
	if (!n_str)
		return (NULL);
	ft_strlcpy(n_str, s + start, len + 1);
	return (n_str);
}
