/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:03:20 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/15 19:34:26 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DLST_H
# define DLST_H

# include <stdlib.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

void	dlst_addback(t_dlist **lst, t_dlist *node);
void	dlst_addfront(t_dlist **lst, t_dlist *node);
void	dlst_clear(t_dlist **lst, void (*del)(void *));
t_dlist	*dlst_last(t_dlist **lst);
int		dlst_len(t_dlist **lst);
t_dlist	*dlst_new(void *content);

#endif
