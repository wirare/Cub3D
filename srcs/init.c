/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:43:37 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 20:37:49 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <app.h>
#include <stdbool.h>
#include <string.h>

void init_player_timing(t_cub3d *cub3d)
{
	t_vector	dir;

	dir = cub3d->player.dir;
	cub3d->player.plane = (t_vector){dir.y * 0.85, -dir.x * 0.85};
	cub3d->timing = (t_timing){0, get_ms(), 0};
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n--)
		return (0);
	if (s2 == NULL)
		return (1);
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
/*
int init_cub3d(t_app *app, char *param)
{
	app->cub3d->sky_color = 0x8c835aff;
	app->cub3d->ground_color = 0x0fc1d1ff;
	reset_display(app);
	app->cub3d->map_width = 24;
	app->cub3d->map_height = 24;
	t_wall worldMap[24][24] =
	{
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,WALL,WALL,WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,WALL,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,DOOR_CLOSE,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,WALL,EMPTY,WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,WALL,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,DOOR_CLOSE,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,EMPTY,WALL,WALL,WALL,WALL,WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL},
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
	};

	app->cub3d->map = malloc(sizeof(int *) * app->cub3d->map_height);
	for (int i = 0; i < app->cub3d->map_height; i++)
	{
		app->cub3d->map[i] = malloc(sizeof(int) * app->cub3d->map_width);
		memcpy(app->cub3d->map[i], worldMap[i], sizeof(int) * app->cub3d->map_width);
	}
	init_player_timing(app->cub3d);
	mlx_mouse_hide(app->mlx);
	memset(app->cub3d->inputs, false, sizeof(bool));
	t_img *textures = app->cub3d->textures;
	if (open_img(app, "wd40.jpg", &textures[N]),
		open_img(app, "patsek.jpg", &textures[E]),
		open_img(app, "merguez.jpg", &textures[S]),
		open_img(app, "kiwi.jpg", &textures[W]),
		open_img(app, "door2.jpg", &textures[D]))
		return (1);//TODO:error if img isnt square or cant open img
	app->cub3d->tas = false;
	app->cub3d->tas_inputs = NULL;
	if (!ft_strncmp("--tas", param, 5))
	{
		app->cub3d->tas = true;
		if (read_tas_file(&app->cub3d->tas_inputs))
			return (1);
	}
	app->cub3d->end = false;
	app->cub3d->update_num = -1;
	return (0);
}
*/
