/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:16:52 by jodougla          #+#    #+#             */
/*   Updated: 2025/07/02 17:04:38 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parsing.h>

char	*skip_space(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (line + i);
}

int	max_line_len(char **map)
{
	int	max;
	int	i;
	int	len;

	max = 0;
	i = 0;
	len = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (max < len)
			max = len;
		i++;
	}
	return (max);
}

int	print_error(char *msg, int ret)
{
	if (ret == 0)
		ft_printf("%s", msg);
	return (1);
}

int	len_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
