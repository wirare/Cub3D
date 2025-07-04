/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:42:20 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/04 21:21:26 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <immintrin.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void	fill(int condition, __m256 color, int *it, uint32_t *pixels)
{
	int			j;
	uint32_t	*row;

	while (*it < condition)
	{
		row = &pixels[*it * WIDTH];
		j = 0;
		while (j < WIDTH - 8)
		{
			_mm256_storeu_si256((__m256i *)(row + j), color);
			j += 8;
		}
		(*it)++;
	}
}

void	fill_screen_fast(uint32_t sky_color, uint32_t ground_color,
						uint32_t *pixels)
{
	__m256		sky;
	__m256		ground;
	int			i;

	sky = _mm256_set1_epi32(sky_color);
	ground = _mm256_set1_epi32(ground_color);
	i = 0;
	fill(HHEIGHT, sky, &i, pixels);
	fill(HEIGHT, ground, &i, pixels);
}

void	generate_empty_display(uint32_t *display, t_cub3d *cub3d, bool *init)
{
	fill_screen_fast(cub3d->sky_color, cub3d->ground_color, display);
	*init = true;
}

void	reset_display(t_app *app)
{
	static uint32_t	empty_screen[HEIGHT * WIDTH] = {0};
	static bool		init = false;
	t_cub3d			*cub3d;

	cub3d = app->cub3d;
	if (init == false)
		generate_empty_display(empty_screen, cub3d, &init);
	memcpy(cub3d->pixels, empty_screen, sizeof(empty_screen));
	mlx_mouse_move(app->mlx, app->win, WIDTH / 2, HEIGHT / 2);
	mlx_clear_window(app->mlx, app->win, (mlx_color)0U);
}
