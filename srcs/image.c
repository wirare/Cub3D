/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:42:15 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:01:17 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "app.h"
#include "mlx.h"

int	open_img(t_app *app, char *path, t_img *dest)
{
	mlx_image	img;
	int			i;
	int			j;

	img = mlx_new_image_from_file(app->mlx, path, &i, &j);
	if (i != j)
	{
		mlx_destroy_image(app->mlx, img);
		printf("Image is not a square\n");
		return (1);
	}
	dest->size = i;
	dest->img = malloc(i * i * sizeof(uint32_t));
	if (dest->img == NULL || img == NULL)
	{
		if (img)
			mlx_destroy_image(app->mlx, img);
		return (2);
	}
	mlx_get_image_region(app->mlx, img, 0, 0, i, i, (mlx_color *)dest->img);
	mlx_destroy_image(app->mlx, img);
	return (0);
}
