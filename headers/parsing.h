/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:57:07 by jodougla          #+#    #+#             */
/*   Updated: 2025/06/13 13:29:28 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>

# define RESET "\033[0m"
# define RED "\033[31m"

# define WALL "1"
# define FLOOR "0"
# define DOOR "D"

# define NORTH "N"
# define SOUTH "S"
# define WEST "W"
# define EAST "E"

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define WEST_TEXTURE "WE"
# define EAST_TEXTURE "EA"
# define FLOOR_COLOR "F"
# define CELLING_COLOR "C"

typedef struct s_texture
{
	char		*path;
	int			width;
	int			heigth;
	mlx_image	img;
	mlx_color	*color;
}	t_texture;

typedef struct s_parsing
{
	int			error;
	char		**file;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	bool	celling_color;
	bool	floor_color;
	bool	north_texture;
	bool	south_texture;
	bool	west_texture;
	bool	east_texture;

}	t_parsing;

void	check_file_name(char *file_name, t_parsing *parsing);
void	parse_file(t_parsing *parsing);
void	parse_texture(char *texture_to_parse, t_parsing *parsing, char *line);

#endif
