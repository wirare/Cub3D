/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectcor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:30:38 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/30 15:39:33 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTCOR_H
# define VECTCOR_H

# include <stdlib.h>

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector	vec_sub(t_vector vec1, t_vector vec2);
t_vector	vec_mult(t_vector vec1, t_vector vec2);
t_vector	vec_div(t_vector vec1, t_vector vec2);
t_vector	vec_add_scalar(t_vector vec, double scalar);
t_vector	vec_sub_scalar(t_vector vec, double scalar);
t_vector	vec_mult_scalar(t_vector vec, double scalar);
t_vector	vec_div_scalar(t_vector vec, double scalar);

#endif
