/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:24:17 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:00:36 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = dest;
	tmp_src = src;
	while (n--)
	{
		*tmp_dest++ = *tmp_src++;
	}
	return (dest);
}
