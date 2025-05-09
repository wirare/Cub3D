/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:54:22 by jodougla          #+#    #+#             */
/*   Updated: 2025/04/09 16:01:11 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <alloc.h>

t_list	**get_alloc(void)
{
	static t_list	*lst;

	if (!lst)
		lst = ft_lstnew(NULL);
	return (&lst);
}

void	push(void *malloc_adress)
{
	t_list	**alloc;

	alloc = get_alloc();
	ft_lstadd_front(alloc, ft_lstnew(malloc_adress));
}

__attribute__ ((destructor)) void	free_alloc(void)
{
	t_list	**alloc;
	t_list	*tmp;

	alloc = get_alloc();
	if (!alloc)
		return ;
	tmp = *alloc;
	while (tmp)
	{
		tmp = (*alloc)->next;
		free ((*alloc)->content);
		free (*alloc);
		*alloc = tmp;
	}
}
