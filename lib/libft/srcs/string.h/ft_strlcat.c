/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:04:32 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:01:11 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size )
{
	int		dst_len;
	int		src_len;
	char	*d;

	if ((!dst || !src) && !size)
		return (size + ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	d = dst + dst_len;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	ft_strlcpy(d, src, size - ft_strlen(dst));
	return (dst_len + src_len);
}
