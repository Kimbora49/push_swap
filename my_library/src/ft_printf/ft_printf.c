/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman_marzouk <ayman_marzouk@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:08:17 by amarzouk          #+#    #+#             */
/*   Updated: 2024/01/03 22:56:23 by ayman_marzo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ft_printf_checker(char c, va_list *args, int *len, int *i)
{
	if (c == 's')
		ft_string(va_arg(*args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_hexa(va_arg(*args, unsigned int), len, c);
	else if (c == 'p')
		ft_pointer(va_arg(*args, unsigned long), len);
	else if (c == 'c')
		ft_ch(va_arg(*args, int), len);
	else if (c == '%')
		ft_ch('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_printf_checker(s[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_ch((char)s[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
