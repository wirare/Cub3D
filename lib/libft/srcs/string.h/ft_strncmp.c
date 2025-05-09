/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:53:18 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:01:31 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n--)
		return (0);
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
