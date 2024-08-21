/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:17:41 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/21 23:27:28 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	nbr;
	long	signe;
	int		i;

	nbr = 0;
	signe = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= (-1);
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		nbr = (nbr * 10) + (nptr[i++] - 48);
	return (nbr * signe);
}
