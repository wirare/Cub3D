/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:27:09 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:27:47 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <SDL2/SDL_scancode.h>

static inline void	move_v(t_cub3d *cub3d, t_player *player,
							t_wall *map_y, double ms)
{
	if (cub3d->inputs[SDL_SCANCODE_W])
	{
		if (!(map_y[(int)(player->pos.x + player->dir.x * ms)] & WALL))
			player->pos.x += player->dir.x * ms;
		if (!(cub3d->map[(int)(player->pos.y + player->dir.y * ms)]
			[(int)(player->pos.x)] & WALL))
			player->pos.y += player->dir.y * ms;
	}
	if (cub3d->inputs[SDL_SCANCODE_S])
	{
		if (!(map_y[(int)(player->pos.x - player->dir.x * ms)] & WALL))
			player->pos.x -= player->dir.x * ms;
		if (!(cub3d->map[(int)(player->pos.y - player->dir.y * ms)]
			[(int)(player->pos.x)] & WALL))
			player->pos.y -= player->dir.y * ms;
	}
}

static inline void	move_h(t_cub3d *cub3d, t_player *player,
							t_wall *map_y, double ms)
{
	if (cub3d->inputs[SDL_SCANCODE_D])
	{
		if (!(map_y[(int)(player->pos.x + player->plane.x * ms)] & WALL))
			player->pos.x += player->plane.x * ms;
		if (!(cub3d->map[(int)(player->pos.y + player->plane.y * ms)]
			[(int)(player->pos.x)] & WALL))
			player->pos.y += player->plane.y * ms;
	}
	if (cub3d->inputs[SDL_SCANCODE_A])
	{
		if (!(map_y[(int)(player->pos.x - player->plane.x * ms)] & WALL))
			player->pos.x -= player->plane.x * ms;
		if (!(cub3d->map[(int)(player->pos.y - player->plane.y * ms)]
			[(int)(player->pos.x)] & WALL))
			player->pos.y -= player->plane.y * ms;
	}
}

void	movement(t_cub3d *cub3d)
{
	t_player	*player;
	double		ms;
	t_wall		*map_y;

	player = &cub3d->player;
	ms = MOVE_SPEED * cub3d->timing.delta_time;
	map_y = cub3d->map[(int)(player->pos.y)];
	move_v(cub3d, player, map_y, ms);
	move_h(cub3d, player, map_y, ms);
}
