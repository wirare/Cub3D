/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:25:44 by ellanglo          #+#    #+#             */
/*   Updated: 2025/04/29 17:44:23 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef APP_H
# define APP_H

# include <mlx_extended.h>
# include <mlx.h>

# define HEIGHT 1080
# define WIDTH 1920
# define NAME "Cub3D"
# define FPS 120

typedef struct s_app
{
	mlx_context	mlx;
	mlx_window	win;
	const char	*name;
}	t_app;

void	app_init(t_app *app);
void	app_destroy(t_app *app);
void	hooks(t_app *app);

#endif
