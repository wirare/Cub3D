/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:00:27 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/02 17:35:48 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

void	single_cast(t_cub3d *cub3d, int x)
{
	t_raycaster_data	rd;
	double				camera_x;
	t_player			*player;
	int					line_height;
	t_vector			draw;

	player = &cub3d->player;
	camera_x = (double)(2) *x / WIDTH - 1;
	rd.ray_dir = vec_add(player->dir, vec_mult_scalar(player->plane, camera_x));
	rd.map_pos = (t_vector){(int)player->pos.x, (int)player->pos.y};
	set_delta(&rd.delta_dist, rd.ray_dir);
	set_ray_dist(&rd, player);
	rd.side = 0;
	hit_loop(&rd, cub3d->map);
	line_height = (int)(HEIGHT / rd.perp_wall_dist);
	draw.x = HHEIGHT - (line_height >> 1);
	draw.y = (line_height >> 1) + HHEIGHT;
	apply_texture(cub3d, rd, draw, x);
}

inline void	raycaster(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		single_cast(cub3d, x);
		x++;
	}
	update_timing(&cub3d->timing);
	calc_minimap(cub3d, cub3d->map, cub3d->pixels, cub3d->player.pos);
}
