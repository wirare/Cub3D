/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:25:44 by ellanglo          #+#    #+#             */
/*   Updated: 2025/06/28 16:47:34 by joshua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef APP_H
# define APP_H

# include <mlx_extended.h>
# include <mlx.h>
# include <math.h>
# include <vector.h>
# include <stdlib.h>
# include <string.h>

# define HEIGHT 1080
# define WIDTH 1920
# define NAME "Cub3D"
# define FPS 120
# define MOVE_SPEED 5
# define ROT_SPEED 3

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_timing
{
	double		old_time;
	double		time;
	double		delta_time;
}	t_timing;

typedef struct s_cub3d
{
	mlx_color	sky_color;
	mlx_color	ground_color;
	mlx_color	pixels[HEIGHT * WIDTH];
	t_player	player;
	t_timing	timing;
	int			map_width;
	int			map_height;
	int			**map;
}	t_cub3d;

typedef struct s_app
{
	mlx_context	mlx;
	mlx_window	win;
	const char	*name;
	t_cub3d		*cub3d;
}	t_app;

void		app_init(t_app *app);
void		app_destroy(t_app *app);
void		hooks(t_app *app);
void		reset_display(t_cub3d *cub3d);
void		init_cub3d(t_app *app);
void		raycaster(t_cub3d *cub3d);
suseconds_t	get_ms(void);

#endif
