/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:25:44 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/03 18:40:31 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef APP_H
# define APP_H

# include <SDL2/SDL_scancode.h>
# include <mlx_extended.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# include <vector.h>
# include <valgrind/valgrind.h>

# define HEIGHT 1080
# define HHEIGHT 540
# define WIDTH 1920
# define HWIDTH 960
# define NAME "Cub3D"
# define FPS 360
# if SLOW
#  define MOVE_SPEED 0.5
#  define ROT_SPEED 0.333
# else
#  define MOVE_SPEED 3
#  define ROT_SPEED 1
# endif
# define MOUSE_ROT_SPEED 3

enum e_dir
{
	N,
	E,
	S,
	W,
	D
};

typedef enum e_wall
{
	EMPTY = 0b00,
	WALL = 0b01,
	DOOR_OPEN = 0b10,
	DOOR_CLOSE = 0b11,
}	t_wall;

typedef struct s_img
{
	uint32_t	*img;
	int			size;
}	t_img;

typedef struct s_trig
{
	double	cos;
	double	mcos;
	double	sin;
	double	msin;
}	t_trig;

typedef struct s_raycatser_data
{
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	step;
	t_vector	map_pos;
	int			side;
	double		perp_wall_dist;
}	t_raycaster_data;

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
	uint32_t	pixels[HEIGHT * WIDTH];
	uint32_t	sky_color;
	uint32_t	ground_color;
	t_player	player;
	t_timing	timing;
	int			map_width;
	int			map_height;
	t_wall		**map;
	t_img		textures[5];
	bool		inputs[SDL_NUM_SCANCODES];
	bool		tas;
	int			**tas_inputs;
	long		update_num;
	bool		end;
}	__attribute__((aligned(32))) t_cub3d;

typedef struct s_app
{
	mlx_context	mlx;
	mlx_window	win;
	const char	*name;
	t_cub3d		*cub3d;
}	t_app;

typedef struct s_draw_ctx
{
	t_cub3d		*cub3d;
	t_img		texture;
	t_vector	draw;
	int			tex_x;
	int			screen_x;
}	t_draw_ctx;

void		app_init(t_app *app);
void		app_destroy(t_app *app);
void		hooks(t_app *app);
void		reset_display(t_app *app);
int			init_cub3d(t_app *app, char *param);
void		raycaster(t_cub3d *cub3d);
void		mouse_movement(t_app *app);
void		movement(t_cub3d *cub3d);
void		rotation(t_cub3d *cub3d);
void		door(t_cub3d *cub3d);
void		calc_minimap(t_cub3d *cub3d, t_wall **map, uint32_t *pixels, t_vector pos);
int			open_img(t_app *app, char *path, t_img *dest);
void		update_timing(t_timing *timing);
void		set_delta(t_vector *deltaDist, t_vector rayDir);
void		set_step(t_vector *step, t_vector rayDir);
void		set_ray_dist(t_raycaster_data *rd, t_player *player);
void		hit_loop(t_raycaster_data *rd, t_wall **map);
void		apply_texture(t_cub3d *cub3d, t_raycaster_data rd, t_vector draw_pos, int x);
int			read_tas_file(int ***tas_inputs);
suseconds_t	get_ms(void);

#endif
