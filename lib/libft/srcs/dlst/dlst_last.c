/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:49:41 by jodougla          #+#    #+#             */
/*   Updated: 2025/06/25 15:25:10 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

t_dlist	*dlst_last(t_dlist **lst)
{
	t_dlist	*tmp;

	tmp = *lst;
	while (tmp->next != *lst)
		tmp = tmp->next;
	return (tmp);
}
