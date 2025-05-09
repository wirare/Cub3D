/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:08:34 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 14:23:11 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <lst.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final_lst;
	t_list	*cpy_lst;

	if (!lst || !f || !del)
		return (NULL);
	final_lst = NULL;
	while (lst)
	{
		cpy_lst = ft_lstnew(f(lst->content));
		if (!cpy_lst)
		{
			del(cpy_lst);
			ft_lstclear(&cpy_lst, del);
			return (NULL);
		}
		if (cpy_lst)
			ft_lstadd_back(&final_lst, cpy_lst);
		lst = lst->next;
	}
	return (final_lst);
}
