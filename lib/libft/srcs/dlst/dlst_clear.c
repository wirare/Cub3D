/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:49 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:05:32 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

void	dlst_clear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = (*lst)->next;
	tmp2 = (*lst)->next->next;
	while (tmp != *lst)
	{
		if (del)
			del(tmp->content);
		free(tmp);
		tmp = tmp2;
		tmp2 = tmp->next;
	}
	if (del)
		del(tmp->content);
	free (*lst);
	free(lst);
}
