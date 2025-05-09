/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodougla <jodougla@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:18:46 by jodougla          #+#    #+#             */
/*   Updated: 2025/02/06 15:54:22 by jodougla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

static int	ft_check_the_string(va_list ap, const char *f_ptr, int len)
{
	if (!*f_ptr)
		return (len);
	if (*f_ptr == 'c')
		len += ft_putchar(va_arg(ap, int));
	if (*f_ptr == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (*f_ptr == 'd')
		len += ft_putnbr(va_arg(ap, int));
	if (*f_ptr == 'i')
		len += ft_putnbr(va_arg(ap, int));
	if (*f_ptr == 'u')
		len += ft_putunsigned_nbr(va_arg(ap, unsigned int));
	if (*f_ptr == 'x')
		len += ft_putnbr_hexa(va_arg(ap, unsigned int), 0);
	if (*f_ptr == 'X')
		len += ft_putnbr_hexa(va_arg(ap, unsigned int), 1);
	if (*f_ptr == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	const char	*f_str;
	va_list		ap;
	int			len;

	if (!str)
		return (-1);
	f_str = str;
	len = 0;
	va_start(ap, str);
	while (*f_str)
	{
		if (*f_str == '%')
		{
			len = ft_check_the_string(ap, f_str + 1, len);
			f_str++;
		}
		else
			len += ft_putchar(*f_str);
		f_str++;
	}
	va_end(ap);
	return (len);
}
