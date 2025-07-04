/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:53 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 21:33:59 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <SDL2/SDL_scancode.h>
#include <app.h>

static inline void	move_v(t_cub3d *cub3d, t_player *player, t_wall *map_y, double ms)
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

static inline void	move_h(t_cub3d *cub3d, t_player *player, t_wall *map_y, double ms)
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

static inline void	rot_right(t_player *player, t_trig trig)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * trig.mcos - player->dir.y * trig.msin;
	player->dir.y = old_dir_x * trig.msin + player->dir.y * trig.mcos;
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * trig.mcos - player->plane.y * trig.msin;
	player->plane.y = old_plane_x * trig.msin + player->plane.y * trig.mcos;
}

static inline void	rot_left(t_player *player, t_trig trig)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * trig.cos - player->dir.y * trig.sin;
	player->dir.y = old_dir_x * trig.sin + player->dir.y * trig.cos;
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * trig.cos - player->plane.y * trig.sin;
	player->plane.y = old_plane_x * trig.sin + player->plane.y * trig.cos;
}

void	rotation(t_cub3d *cub3d)
{
	t_player	*player;
	double		rot_speed;
	t_trig		trig;

	player = &cub3d->player;
	rot_speed = ROT_SPEED * cub3d->timing.delta_time;
	trig = (t_trig){cos(rot_speed), cos(-rot_speed),
		sin(rot_speed), sin(-rot_speed)};
	if (cub3d->inputs[SDL_SCANCODE_RIGHT])
		rot_right(player, trig);
	if (cub3d->inputs[SDL_SCANCODE_LEFT])
		rot_left(player, trig);
}

static inline void	inner_door_while(int i, t_vector pos, t_cub3d *cub3d, t_wall **map)
{
	int		j;
	t_wall	*block;

	j = -3;
	while (j < 3)
	{
		j++;
		if (i == 0 && j == 0)
			continue ;
		if (pos.y + j < 0 || pos.y + j >= cub3d->map_height
			|| pos.x + i < 0 || pos.x + i >= cub3d->map_width)
			continue ;
		block = &map[(int)pos.y + j][(int)pos.x + i];
		if (*block & 2)
			*block ^= 1;
	}
}

void	door(t_cub3d *cub3d)
{
	static suseconds_t	last_interaction = 0;
	t_vector			pos;
	int					i;
	t_wall				**map;

	pos = cub3d->player.pos;
	map = cub3d->map;
	if (cub3d->inputs[SDL_SCANCODE_O] && get_ms() - last_interaction >= 200)
	{
		i = -2;
		while (i < 3)
		{
			inner_door_while(i, pos, cub3d, map);
			i++;
		}
		last_interaction = get_ms();
	}
}
