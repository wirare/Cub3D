/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_vargs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:44:44 by jodougla          #+#    #+#             */
/*   Updated: 2025/03/18 16:43:16 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_free.h"
#include <ft_str.h>

void	put_in_tab(va_list ap, char **tab, int n_arg)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	while (i != n_arg)
	{
		str = va_arg(ap, char *);
		len = ft_strlen(str);
		*tab = ft_calloc(sizeof(char), len + 1);
		ft_memcpy(*tab, str, len);
		tab++;
		i++;
	}
}

char	*join_all(char **tab, char *str)
{
	int	i;
	int	j;
	int	offset;
	int	len;

	i = 0;
	offset = 0;
	while (tab[i])
	{
		j = 0;
		len = ft_strlen(tab[i]);
		while (tab[i][j])
		{
			str[j + offset] = tab[i][j];
			j++;
		}
		offset += len;
		i++;
	}
	return (str);
}

char	*ft_strjoin_vargs(int n_arg, ...)
{
	va_list	ap;
	char	*final_str;
	char	**tab;
	int		total_len;
	int		i;

	va_start(ap, n_arg);
	total_len = 0;
	i = 0;
	tab = ft_calloc(sizeof(char *), n_arg + 1);
	if (!tab)
	{
		va_end(ap);
		return (NULL);
	}
	put_in_tab(ap, tab, n_arg);
	while (i != n_arg)
		total_len += ft_strlen(tab[i++]);
	final_str = ft_calloc(sizeof(char), total_len + 1);
	join_all(tab, final_str);
	va_end(ap);
	ft_free(tab);
	return (final_str);
}
