/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:44:18 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:47:25 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FD_H
# define FT_FD_H

# include <unistd.h>
# include <stdarg.h>

void	close_fd(int num_fd, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
