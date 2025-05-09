/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:59:39 by jodougla          #+#    #+#             */
/*   Updated: 2025/03/18 15:32:43 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <lst.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst)
		return ;
	last_node = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new;
}
