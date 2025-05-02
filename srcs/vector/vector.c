/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:30:26 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/30 15:42:16 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

__attribute__((const))
t_vector	vec_add(t_vector vec1, t_vector vec2)
{
	t_vector	vec_res;

	vec_res.x = vec1.x + vec2.x;
	vec_res.y = vec1.y + vec2.y;
	return (vec_res);
}

__attribute__((const))
t_vector	vec_sub(t_vector vec1, t_vector vec2)
{
	t_vector	vec_res;

	vec_res.x = vec1.x - vec2.x;
	vec_res.y = vec1.y - vec2.y;
	return (vec_res);
}

__attribute__((const))
t_vector	vec_mult(t_vector vec1, t_vector vec2)
{
	t_vector	vec_res;

	vec_res.x = (vec1.x * vec2.x) - (vec1.y * vec2.y);
	vec_res.y = (vec1.x * vec2.y) + (vec1.y * vec2.x);
	return (vec_res);
}

__attribute__((const))
t_vector	vec_div(t_vector vec1, t_vector vec2)
{
	t_vector	vec_res;
	double		c2_plus_d2;

	c2_plus_d2 = (vec2.x * vec2.x) + (vec2.y * vec2.y);
	vec_res.x = (vec1.x * vec2.x) + (vec1.y * vec2.y);
	vec_res.x /= c2_plus_d2;
	vec_res.y = (vec1.y * vec2.x) - (vec1.x * vec2.y);
	vec_res.y /= c2_plus_d2;
	return (vec_res);
}
