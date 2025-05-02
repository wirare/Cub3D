/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:37:39 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/30 15:39:05 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

__attribute__((const))
t_vector	vec_add_scalar(t_vector vec, double scalar)
{
	t_vector	vec_res;

	vec_res.x = vec.x + scalar;
	vec_res.y = vec.y + scalar;
	return (vec_res);
}

__attribute__((const))
t_vector	vec_sub_scalar(t_vector vec, double scalar)
{
	t_vector	vec_res;

	vec_res.x = vec.x - scalar;
	vec_res.y = vec.y - scalar;
	return (vec_res);
}

__attribute__((const))
t_vector	vec_mult_scalar(t_vector vec, double scalar)
{
	t_vector	vec_res;

	vec_res.x = vec.x * scalar;
	vec_res.y = vec.y * scalar;
	return (vec_res);
}

__attribute__((const))
t_vector	vec_div_scalar(t_vector vec, double scalar)
{
	t_vector	vec_res;

	if (scalar == 0)
		return (vec);
	vec_res.x = vec.x / scalar;
	vec_res.y = vec.y / scalar;
	return (vec_res);
}
