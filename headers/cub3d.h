/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:08:27 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/04 12:47:32 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <parsing.h>
# include <app.h>
# include <vector.h>

void	prep_exec(t_parsing parsing, int tas);
void	set_texture(t_parsing *parsing, t_app app);
int		check_argc(int argc, char **argv);
void	free_parsing(t_parsing parsing);
void	set_parsing(t_parsing *parsing);
void	init_player_timing(t_cub3d *cub3d);

#endif
