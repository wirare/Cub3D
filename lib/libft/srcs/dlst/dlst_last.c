/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:49:41 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:05:39 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

t_dlist	*dlst_last(t_dlist **lst)
{
	t_dlist	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp->next != *lst)
		tmp = tmp->next;
	return (tmp);
}
