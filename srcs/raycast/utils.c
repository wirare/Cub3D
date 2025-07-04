/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:18:22 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 18:09:49 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

inline void	update_timing(t_timing *timing)
{
	timing->old_time = timing->time;
	timing->time = get_ms();
	timing->delta_time = (timing->time - timing->old_time) / 1000.0;
}

inline void	set_delta(t_vector *delta_dist, t_vector ray_dir)
{
	delta_dist->x = 1e30;
	if (ray_dir.x != 0)
		delta_dist->x = fabs(1 / ray_dir.x);
	delta_dist->y = 1e30;
	if (ray_dir.y != 0)
		delta_dist->y = fabs(1 / ray_dir.y);
}

inline void	set_step(t_vector *step, t_vector ray_dir)
{
	step->x = 1 - 2 * signbit(ray_dir.x);
	step->y = 1 - 2 * signbit(ray_dir.y);
}

inline void	set_ray_dist(t_raycaster_data *rd, t_player *player)
{
	rd->side_dist.x = (rd->map_pos.x + 1.0 - player->pos.x) * rd->delta_dist.x;
	if (rd->ray_dir.x < 0)
		rd->side_dist.x = (player->pos.x - rd->map_pos.x) * rd->delta_dist.x;
	rd->side_dist.y = (rd->map_pos.y + 1.0 - player->pos.y) * rd->delta_dist.y;
	if (rd->ray_dir.y < 0)
		rd->side_dist.y = (player->pos.y - rd->map_pos.y) * rd->delta_dist.y;
}

void	hit_loop(t_raycaster_data *rd, t_wall **map)
{
	t_wall	*space_value;

	set_step(&rd->step, rd->ray_dir);
	space_value = &map[(int)rd->map_pos.y][(int)rd->map_pos.x];
	while (!(*space_value & WALL))
	{
		if (rd->side_dist.x < rd->side_dist.y)
		{
			rd->side_dist.x += rd->delta_dist.x;
			rd->map_pos.x += rd->step.x;
			rd->side = 1 - (rd->step.x > 0);
		}
		else
		{
			rd->side_dist.y += rd->delta_dist.y;
			rd->map_pos.y += rd->step.y;
			rd->side = 3 - (rd->step.y > 0);
		}
		space_value = &map[(int)rd->map_pos.y][(int)rd->map_pos.x];
	}
	rd->perp_wall_dist = (rd->side_dist.y - rd->delta_dist.y);
	if (rd->side < 2)
		rd->perp_wall_dist = (rd->side_dist.x - rd->delta_dist.x);
}
