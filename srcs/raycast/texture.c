/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:22:08 by ellanglo          #+#    #+#             */
/*   Updated: 2025/07/01 19:24:25 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <app.h>

static inline t_img	get_texture(t_cub3d *cub3d, t_wall type, int side)
{
	if (type == WALL)
		return (cub3d->textures[side]);
	return (cub3d->textures[D]);
}

static inline int	calc_tex_x(t_img texture, t_raycaster_data *rd,
								t_cub3d *cub3d)
{
	double	wall_x;
	int		tex_x;

	if (rd->side < 2)
		wall_x = cub3d->player.pos.y + rd->perp_wall_dist * rd->ray_dir.y;
	else
		wall_x = cub3d->player.pos.x + rd->perp_wall_dist * rd->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture.size);
	if ((rd->side == N && rd->ray_dir.x > 0)
		|| (rd->side == E && rd->ray_dir.x > 0)
		|| (rd->side == S && rd->ray_dir.y < 0)
		|| (rd->side == W && rd->ray_dir.y < 0))
		tex_x = texture.size - tex_x - 1;
	return (tex_x);
}

static inline void	draw_pixels(t_draw_ctx *ctx, float step, float tex_pos)
{
	uint32_t	*pixels;
	uint32_t	*pixel_ptr;
	int			offset;
	int			pixel_count;

	pixels = ctx->cub3d->pixels;
	pixel_ptr = &pixels[(int)ctx->draw.x * WIDTH + ctx->screen_x];
	pixel_count = ctx->draw.y - ctx->draw.x;
	offset = 0;
	while (offset < pixel_count && offset < HEIGHT)
	{
		pixel_ptr[offset * WIDTH] = ctx->texture.img[
			(int)tex_pos * ctx->texture.size + ctx->tex_x];
		tex_pos += step;
		offset++;
	}
}

static inline void	draw_loop(t_draw_ctx *ctx)
{
	float	step;
	float	tex_pos;
	int		line_height;

	line_height = ctx->draw.y - ctx->draw.x;
	step = (float)ctx->texture.size / line_height;
	tex_pos = 0;
	if (ctx->draw.x < 0)
	{
		tex_pos = step * (-ctx->draw.x);
		ctx->draw.x = 0;
	}
	draw_pixels(ctx, step, tex_pos);
}

inline void	apply_texture(t_cub3d *cub3d, t_raycaster_data rd,
							t_vector draw_pos, int x)
{
	t_wall		wall_type;
	t_img		texture;
	int			tex_x;
	t_draw_ctx	ctx;

	wall_type = cub3d->map[(int)rd.map_pos.y][(int)rd.map_pos.x];
	texture = get_texture(cub3d, wall_type, rd.side);
	tex_x = calc_tex_x(texture, &rd, cub3d);
	ctx = (t_draw_ctx){cub3d, texture, draw_pos, tex_x, x};
	draw_loop(&ctx);
}
