/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:14:09 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 23:20:11 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <stdint.h>
#include <immintrin.h>

#define UNIT 8
#define MINIMAP_RADIUS 6
#define MINIMAP_CENTER 10
#define PLAYER_DOT_SIZE 6
#define PLAYER_COLOR 0xFF0000FF

void	draw_unit_fast(t_vector screen_pos, uint32_t *pixels, __m256i color_vec)
{
	int	i;
	int	base_index;

	i = 0;
	while (i < UNIT)
	{
		base_index = (screen_pos.y + i) * WIDTH + screen_pos.x;
		_mm256_storeu_si256((__m256i *)&pixels[base_index], color_vec);
		i++;
	}
}

void	draw_player_dot(uint32_t *pixels)
{
	int			center_x;
	int			center_y;
	int			px;
	int			py;
	t_vector	it;

	center_x = 59;
	center_y = 59;
	it = (t_vector){0, 0};
	while (it.y < PLAYER_DOT_SIZE)
	{
		it.x = 0;
		while (it.x < PLAYER_DOT_SIZE)
		{
			px = center_x + it.x;
			py = center_y + it.y;
			pixels[py * WIDTH + px] = 0xFF0000FF;
			it.x++;
		}
		it.y++;
	}
}

static inline void	inner_minimap_calc(t_vector indexs, t_wall **map,
										t_cub3d *cub3d, t_vector pos)
{
	t_vector	map_pos;
	uint32_t	color;
	t_vector	screen_pos;

	indexs.x = -MINIMAP_RADIUS;
	while (indexs.x <= MINIMAP_RADIUS)
	{
		map_pos = (t_vector){(int)pos.x + indexs.x, (int)pos.y + indexs.y};
		color = 0x000000FF;
		if (map_pos.y >= 0 && map_pos.y < cub3d->map_height
			&& map_pos.x >= 0 && map_pos.x < cub3d->map_width)
		{
			color = 0x888888F;
			if (map[(int)map_pos.y][(int)map_pos.x] & WALL)
				color = 0x000000FF;
		}
		screen_pos.x = MINIMAP_CENTER + (-indexs.x + MINIMAP_RADIUS) * UNIT;
		screen_pos.y = MINIMAP_CENTER + (indexs.y + MINIMAP_RADIUS) * UNIT;
		draw_unit_fast(screen_pos, cub3d->pixels, _mm256_set1_epi32(color));
		indexs.x++;
	}
}

void	calc_minimap(t_cub3d *cub3d, t_wall **map, uint32_t *pixels,
						t_vector pos)
{
	t_vector	indexs;

	indexs = (t_vector){-MINIMAP_RADIUS, -MINIMAP_RADIUS};
	while (indexs.y <= MINIMAP_RADIUS)
	{
		inner_minimap_calc(indexs, map, cub3d, pos);
		indexs.y++;
	}
	draw_player_dot(pixels);
}
