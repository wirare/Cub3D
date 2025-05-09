/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:23:45 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:00:45 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	tmp_dest = dest;
	tmp_src = src;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		while (n--)
		{
			tmp_dest[n] = tmp_src[n];
		}
	}
	else
	{
		while (n--)
			*tmp_dest++ = *tmp_src++;
	}
	return (dest);
}
