/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:53 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/02 17:34:25 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <SDL2/SDL_scancode.h>
#include <app.h>

void	movement(t_cub3d *cub3d)
{
	t_player	*player;
	double		move_speed;
	t_wall		*map_y;

	player = &cub3d->player;
	move_speed = MOVE_SPEED * cub3d->timing.delta_time;
	map_y = cub3d->map[(int)(player->pos.y)];
	if (cub3d->inputs[SDL_SCANCODE_W])
	{
		if (!(map_y[(int)(player->pos.x + player->dir.x * move_speed)] & 1))
			player->pos.x += player->dir.x * move_speed;
		if (!(cub3d->map[(int)(player->pos.y + player->dir.y * move_speed)][(int)(player->pos.x)] & 1))
			player->pos.y += player->dir.y * move_speed;
	}
	if (cub3d->inputs[SDL_SCANCODE_S])
	{
		if (!(map_y[(int)(player->pos.x - player->dir.x * move_speed)] & 1))
			player->pos.x -= player->dir.x * move_speed;
		if (!(cub3d->map[(int)(player->pos.y - player->dir.y * move_speed)][(int)(player->pos.x)] & 1))
			player->pos.y -= player->dir.y * move_speed;
	}
	if (cub3d->inputs[SDL_SCANCODE_D])
	{
		if (!(map_y[(int)(player->pos.x + player->plane.x * move_speed)] & 1))
			player->pos.x += player->plane.x * move_speed;
		if (!(cub3d->map[(int)(player->pos.y + player->plane.y * move_speed)][(int)(player->pos.x)] & 1))
			player->pos.y += player->plane.y * move_speed;
	}
	if (cub3d->inputs[SDL_SCANCODE_A])
	{
		if (!(map_y[(int)(player->pos.x - player->plane.x * move_speed)] & 1))
			player->pos.x -= player->plane.x * move_speed;
		if (!(cub3d->map[(int)(player->pos.y - player->plane.y * move_speed)][(int)(player->pos.x)] & 1))
			player->pos.y -= player->plane.y * move_speed;
	}
}

void	rotation(t_cub3d *cub3d)
{
	t_player	*player;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;
	t_trig		trig;

	player = &cub3d->player;
	rot_speed = ROT_SPEED * cub3d->timing.delta_time;
	trig = (t_trig){cos(rot_speed), cos(-rot_speed),
		sin(rot_speed), sin(-rot_speed)};
	if (cub3d->inputs[SDL_SCANCODE_RIGHT])
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * trig.mcos - player->dir.y * trig.msin;
		player->dir.y = old_dir_x * trig.msin + player->dir.y * trig.mcos;
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * trig.mcos - player->plane.y * trig.msin;
		player->plane.y = old_plane_x * trig.msin + player->plane.y * trig.mcos;
	}
	if (cub3d->inputs[SDL_SCANCODE_LEFT])
	{
		old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * trig.cos - player->dir.y * trig.sin;
		player->dir.y = old_dir_x * trig.sin + player->dir.y * trig.cos;
		old_plane_x = player->plane.x;
		player->plane.x = player->plane.x * trig.cos - player->plane.y * trig.sin;
		player->plane.y = old_plane_x * trig.sin + player->plane.y * trig.cos;
	}
}

void	door(t_cub3d *cub3d)
{
	static suseconds_t	last_interaction = 0;
	t_vector			pos;
	int					i;
	int					j;
	t_wall				**map;

	pos = cub3d->player.pos;
	map = cub3d->map;
	if (cub3d->inputs[SDL_SCANCODE_O] && get_ms() - last_interaction >= 200)
	{
		i = -2;
		while (i < 3)
		{
			j = -3;
			while (j < 3)
			{
				j++;
				if (i == 0 && j == 0)
					continue ;
				if (map[(int)pos.y + j][(int)pos.x + i] & 2)
					map[(int)pos.y + j][(int)pos.x + i] ^= 1;
			}
			i++;
		}
		last_interaction = get_ms();
	}
}
