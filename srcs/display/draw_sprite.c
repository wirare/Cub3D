/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:42:26 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/05 01:12:28 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void	draw_sprite(t_app *app)
{
	static int	counter = 0;
	static int	img_idx = 0;

	if (counter % 40 == 0)
		img_idx = (img_idx + 1) % 5;
	mlx_put_transformed_image_to_window(app->mlx, app->win,
		app->cub3d->sprite[img_idx], 0, 785,
		(float)1 / 4, (float)1 / 4, 0);
	counter++;
	counter %= 200;
}
