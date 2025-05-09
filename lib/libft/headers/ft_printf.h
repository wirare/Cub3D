/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:53:07 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:54:02 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXA_UPPER "0123456789ABCDEF"
# define HEXA_LOWER "0123456789abcdef"
# define INT_MIN "-2147483648"

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunsigned_nbr(unsigned int nb);
int		ft_putchar_hexa(unsigned int nb, int flag);
int		ft_putnbr_hexa(unsigned int nb, int flag);
int		ft_putptr(unsigned long str);
int		ft_putnbr_mem(unsigned long nb, int flag);

#endif
