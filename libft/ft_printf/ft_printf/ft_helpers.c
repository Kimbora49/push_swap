/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddifalla <ddifalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:54:16 by ddifalla          #+#    #+#             */
/*   Updated: 2024/06/18 15:07:13 by ddifalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//-------------------------ft_putchar_fd
void	ft_putchar_fd(char c, int *pj, int fd)
{
	*pj += 1;
	write(fd, &c, 1);
}

//-------------------------ft_putnbr_fd
void	ft_putnbr_fd(int n, int *pj, int fd)
{
	if (n == -2147483648)
	{
		*pj += 11;
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', pj, fd);
		ft_putnbr_fd(n *(-1), pj, fd);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, pj, fd);
	else
	{
		ft_putnbr_fd(n / 10, pj, fd);
		ft_putnbr_fd(n % 10, pj, fd);
	}
}

//-------------------------ft_putnbr_base_fd
void	ft_putnbr_base(unsigned long long n, char *base, int *pj, char c)
{
	if (c == 'p')
	{
		if (n != 0)
		{
			*pj += 2;
			write(1, "0x", 2);
		}
		if (n == 0)
		{
			*pj += 5;
			write(1, "(nil)", 5);
			return ;
		}
		c++;
	}
	if (c != 'p')
	{
		if (n >= 16)
			ft_putnbr_base(n / 16, base, pj, c);
		ft_putchar_fd(base[n % 16], pj, 1);
	}
}

//-------------------------ft_putunsnbr_fd
void	ft_putunsnbr_fd(unsigned int n, int *pj, int fd)
{
	if (n >= 10)
	{
		ft_putunsnbr_fd(n / 10, pj, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + 48, pj, fd);
}

//-------------------------ft_putstr_fd
void	ft_putstr_fd(char *s, int *pj, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		*pj += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
		*pj += 1;
	}
}
