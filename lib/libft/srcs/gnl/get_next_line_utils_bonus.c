/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:09:23 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:57:11 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <gnl.h>

size_t	ft_strlen_gnl(char *str)
{
	char	*tmp_str;

	if (!str)
		return (0);
	tmp_str = str;
	while (*tmp_str)
		tmp_str++;
	return (tmp_str - str);
}

char	*ft_strnjoin(char *s1, char *s2, int len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s2)
		return (NULL);
	dest = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	while (*s2 && len--)
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
