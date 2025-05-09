/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:33:30 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:05:17 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

void	dlst_addback(t_dlist **lst, t_dlist *node)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;
	t_dlist	*head;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	tmp = *lst;
	tmp2 = (*lst)->next;
	head = *lst;
	while (tmp2 && tmp->next != head)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp2 = node;
	tmp2->next = head;
	tmp2->prev = tmp;
	tmp->next = tmp2;
	head->prev = tmp2;
}
