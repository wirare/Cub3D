/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:42:20 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/01 19:31:59 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>
#include <immintrin.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void	fill_screen_fast(uint32_t sky_color, uint32_t ground_color,
						uint32_t *pixels)
{
	__m256		sky;
	__m256		ground;
	uint32_t	*row;
	int			i;
	int			j;

	sky = _mm256_set1_epi32(sky_color);
	ground = _mm256_set1_epi32(ground_color);
	i = 0;
	while (i < HHEIGHT)
	{
		row = &pixels[i * WIDTH];
		j = 0;
		while (j < WIDTH - 8)
		{
			_mm256_storeu_si256((__m256i *)(row + j), sky);
			j += 8;
		}
		i++;
	}
	while (i < HEIGHT)
	{
		row = &pixels[i * WIDTH];
		j = 0;
		while (j < WIDTH - 8)
		{
			_mm256_storeu_si256((__m256i *)(row + j), ground);
			j += 8;
		}
		i++;
	}
}

void	generate_empty_display(uint32_t *display, t_cub3d *cub3d, bool *init)
{
	int	i;
	int	j;

	if (HEIGHT * WIDTH % 8 != 0)
	{
		i = 0;
		while (i++ < HEIGHT / 2)
		{
			j = 0;
			while (j++ < WIDTH)
				cub3d->pixels[i * WIDTH + j] = cub3d->sky_color;
		}
		i = (HEIGHT / 2);
		while (i++ < HEIGHT)
		{
			j = 0;
			while (j < WIDTH)
				cub3d->pixels[i * WIDTH + j] = cub3d->ground_color;
		}
	}
	else
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
