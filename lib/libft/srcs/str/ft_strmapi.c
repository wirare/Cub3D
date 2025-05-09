/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 02:59:45 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:21:30 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_str.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		index;
	int			len;
	char		*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	index = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
	{
		while (index < ft_strlen(s))
		{
			str[index] = f(index, s[index]);
			index++;
		}
	}
	return (str);
}
