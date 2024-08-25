/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:32:35 by ddifalla          #+#    #+#             */
/*   Updated: 2024/06/20 16:51:43 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_testers(int *pj, va_list args, const char *format, int i)
{
	i++;
	ft_regroupft(pj, args, format[i], 1);
	ft_regroupft2(pj, args, format[i], 1);
	return (i);
}

void	ft_regroupft(int *pj, va_list args, const char formatc, int fd)
{
	if (formatc == 'c')
		ft_putchar_fd(va_arg(args, int), pj, fd);
	else if (formatc == 's')
		ft_putstr_fd(va_arg(args, char *), pj, fd);
	else if (formatc == 'p')
		ft_putnbr_base(\
			va_arg(args, unsigned long long), "0123456789abcdef", pj, formatc);
	else if (formatc == 'd' || formatc == 'i')
		ft_putnbr_fd(va_arg(args, int), pj, fd);
}

void	ft_regroupft2(int *pj, va_list args, const char formatc, int fd)
{
	if (formatc == 'u')
		ft_putunsnbr_fd(va_arg(args, unsigned int), pj, fd);
	else if (formatc == 'x')
		ft_putnbr_base(\
			va_arg(args, unsigned int), "0123456789abcdef", pj, formatc);
	else if (formatc == 'X')
		ft_putnbr_base(\
			va_arg(args, unsigned int), "0123456789ABCDEF", pj, formatc);
	else if (formatc == '%')
		ft_putchar_fd('%', pj, fd);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	args;

	va_start(args, format);
	i = 0;
	j = 0;
	if ((!format || format[i] == '%') && format[i + 1] == '\0')
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_testers(&j, args, format, i) + 1;
		else
		{
			ft_putchar_fd(format[i], &j, 1);
			i++;
		}
	}
	va_end(args);
	return (j);
}
