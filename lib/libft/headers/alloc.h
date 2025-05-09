/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:55:35 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/24 12:57:00 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ALLOC_H
# define ALLOC_H

# include "lst.h"

void	push(void *malloc_adress);
void	free_manager(void *adress);
t_list	**get_alloc(void);

#endif
