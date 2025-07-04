/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:57:07 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/04 21:52:09 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <app.h>

# define P_WALL '1'
# define P_FLOOR '0'
# define P_DOOR 'D'

# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define WEST_TEXTURE "WE"
# define EAST_TEXTURE "EA"
# define DOOR_ "DT"
# define FLOOR_COLOR "F"
# define CELLING_COLOR "C"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_texture
{
	char		*path;
	int			width;
	int			heigth;
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
	t_texture	dt;
	t_color		*celling;
	t_color		*floor;
	char		**map;

}	t_parsing;

void	check_file_name(char *file_name, t_parsing *parsing);
int		parse_file(t_parsing *parsing);
int		parse_texture(char *texture_to_parse, t_parsing *parsing, char *line);
int		parse_color(t_parsing *parsing, char *line, char type);
char	*skip_space(char *line);
int		parse_map(t_parsing parsing);
int		prep_floodfill(char **map);
int		max_line_len(char **map);
int		print_error(char *msg, int ret);
int		len_array(char **str);

#endif
