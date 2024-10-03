/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:45:58 by amarzouk          #+#    #+#             */
/*   Updated: 2024/01/11 15:57:09 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == 32 || *str == '\t' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && (*str
					- 48) > LONG_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		result = result * 10 + (*str++ - 48);
	}
	return (result * sign);
}
