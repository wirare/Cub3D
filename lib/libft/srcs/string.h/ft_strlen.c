/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:44:27 by ellanglo          #+#    #+#             */
/*   Updated: 2025/02/15 19:37:59 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_string.h>

size_t	ft_strlen(const char *s)
{
	const char		*start;
	const size_t	*s_cp;

	start = s;
	while ((unsigned long)s & 7)
	{
		if (!*s)
			return (s - start);
		s++;
	}
	s_cp = (const size_t *)s;
	while (!((*s_cp - ONES) & ~(*s_cp) & HIGHS))
		s_cp++;
	s = (const char *)s_cp;
	while (*s)
		s++;
	return (s - start);
}
