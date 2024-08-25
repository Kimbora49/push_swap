/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:49:54 by ddifalla          #+#    #+#             */
/*   Updated: 2024/06/20 14:21:47 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>    

// PROTOTYPES
int		ft_printf(const char *format, ...);
void	ft_putunsnbr_fd(unsigned int n, int *pj, int fd);
void	ft_putchar_fd(char c, int *pj, int fd);
void	ft_putnbr_fd(int n, int *pj, int fd);
void	ft_putstr_fd(char *s, int *pj, int fd);
int		ft_testers(int *pj, va_list args, const char *format, int i);
void	ft_regroupft(int *pj, va_list args, const char formatc, int fd);
void	ft_regroupft2(int *pj, va_list args, const char formatc, int fd);
void	ft_putnbr_base(unsigned long long n, char *base, int *pj, char c);

#endif