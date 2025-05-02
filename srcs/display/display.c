/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:42:20 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/29 20:08:25 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void reset_display(t_cub3d *cub3d)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				cub3d->pixels[i * WIDTH + j] = cub3d->sky_color;
			else
				cub3d->pixels[i * WIDTH + j] = cub3d->ground_color;
			j++;
		}
		i++;
	}
}
