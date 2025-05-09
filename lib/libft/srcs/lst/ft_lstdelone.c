/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 04:25:38 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 14:22:54 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <lst.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = lst->next;
	del(lst->content);
	free(lst);
	lst = tmp;
}
