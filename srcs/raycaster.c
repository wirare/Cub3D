/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:00:27 by ellanglo          #+#    #+#             */
/*   Updated: 2025/05/14 10:13:42 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <stdio.h>
void	update_timing(t_timing *timing)
{
	timing->old_time = timing->time;
//	timing->time = get_ms();
	timing->delta_time = (timing->time - timing->old_time) / 1000.0;
	//printf("Delta time: %f\n", 1/timing->delta_time);
}

void raycaster(t_cub3d *cub3d)
{
	double		cameraX;
	t_vector	rayDir;
	t_player	*player;
	t_vector	mapPos;
	t_vector	sideDist;
	t_vector	deltaDist;
	double		perpWallDist;
	t_vector	step;
	unsigned int	color;
	int			hit;
	int			side;
	int			x;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;

	x = 0;
	player = &cub3d->player;
	while (x < WIDTH)
	{
		cameraX = (double)2 * x / (double)WIDTH - 1;
		rayDir = vec_add(player->dir, vec_mult_scalar(player->plane, cameraX));
		mapPos = (t_vector){(int)player->pos.x, (int)player->pos.y};
		if (rayDir.x == 0)
			deltaDist.x = 1e30;
		else
			deltaDist.x = fabs(1/rayDir.x);
		if (rayDir.y == 0)
			deltaDist.y = 1e30;
		else
			deltaDist.y = fabs(1/rayDir.y);
		if (rayDir.x < 0)
		{
			step.x = -1;
			sideDist.x = (player->pos.x - mapPos.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (mapPos.x + 1.0 - player->pos.x) * deltaDist.x;
		}
		if (rayDir.y < 0)
		{
			step.y = -1;
			sideDist.y = (player->pos.y - mapPos.y) * deltaDist.y;
		}
		else
		{
			step.y = 1;
			sideDist.y = (mapPos.y + 1.0 - player->pos.y) * deltaDist.y;
		}
		hit = 0;
		while (!hit)
		{
			if (sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				mapPos.x += step.x;
				side = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				mapPos.y += step.y;
				side = 1;
			}
			if (cub3d->map[(int)mapPos.y][(int)mapPos.x])
				hit = 1;
		}
		if (side == 0)
			perpWallDist = sideDist.x - deltaDist.x;
		else
			perpWallDist = sideDist.y - deltaDist.y;
		lineHeight = (int)(HEIGHT / perpWallDist);
		drawStart = - lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		switch (cub3d->map[(int)mapPos.y][(int)mapPos.x])
		{
			case 1: color = 0xFF0000FFU; break;
			case 2: color = 0x00FF00FFU; break;
			case 3: color = 0x0000FFFFU; break;
			case 4: color = 0xFFFFFFFFU; break;
			default: color = 0xFFFF00FFU; break;
		}
		if (side == 1)
			color = color/2;
		while (drawStart < drawEnd)
		{
			cub3d->pixels[drawStart * WIDTH + x] = (mlx_color)color;
			drawStart++;
		}
		x++;
	}
	update_timing(&cub3d->timing);
}
