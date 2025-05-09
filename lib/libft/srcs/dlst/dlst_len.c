/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:09:44 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:05:45 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

int	dlst_len(t_dlist **lst)
{
	t_dlist	*tmp;
	int		i;

	tmp = *lst;
	i = 1;
	if (!lst)
		return (0);
	while (tmp->next != *lst)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
