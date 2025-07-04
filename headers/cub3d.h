/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:08:27 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/05 00:37:12 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <parsing.h>
# include <app.h>
# include <vector.h>
# include <sys/time.h>

void	prep_exec(t_parsing parsing, int tas);
int		set_texture(t_parsing *parsing, t_app app);
int		check_argc(int argc, char **argv);
void	free_parsing(t_parsing parsing);
void	set_parsing(t_parsing *parsing);
void	init_player_timing(t_cub3d *cub3d);
void	pad_for_exec(t_parsing parsing, t_app *app);
void	get_player_pos(char **map, t_vector *pos, t_vector *dir);
void	get_dir(char **map, int i, int j, t_vector *dir);
void	delete_img(t_app app);
void	set_color(t_parsing parsing, t_app *app);
int		context_error(mlx_context mlx);
int		window_error(t_app app);
int		check_tas(t_app *app, int tas);
void	error_file(t_parsing parsing);

#endif
