/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:32:58 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:07:32 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <dlst.h>

t_dlist	*dlst_new(void *content)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->prev = node;
	node->next = node;
	node->content = content;
	return (node);
}
