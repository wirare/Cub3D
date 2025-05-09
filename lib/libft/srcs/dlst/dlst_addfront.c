/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_addfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:40:26 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:05:24 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

void	dlst_addfront(t_dlist **lst, t_dlist *node)
{
	t_dlist	*tmp;

	if (!node || !lst)
		return ;
	node->next = *lst;
	if (*lst)
	{
		tmp = *lst;
		(*lst)->prev = node;
		while (tmp->next && tmp->next != *lst)
			tmp = tmp->next;
		node->prev = tmp;
		tmp->next = node;
	}
	*lst = node;
}
