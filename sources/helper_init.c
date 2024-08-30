/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:49:23 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/30 14:27:06 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	list_len(t_node *list)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_node	*find_max(t_node *list)
{
	long	max;
	t_node	*tmp_max;

	if (!list)
		return (NULL);
	max = LONG_MIN;
	while (list)
	{
		if (list->nbr > max)
		{
			max = list->nbr;
			tmp_max = list;
		}
		list = list->next;
	}
	return (tmp_max);
}

t_node	*find_min(t_node *list)
{
	long	min;
	t_node	*tmp_min;

	if (!list)
		return (0);
	min = LONG_MAX;
	while (list)
	{
		if (list->nbr < min)
		{
			min = list->nbr;
			tmp_min = list;
		}
		list = list->next;
	}
	return (tmp_min);
}

t_node	*get_cheapest(t_node *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->cheapest)
			return (list);
		list = list->next;
	}
	return (NULL);
}
long	ft_atol(char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
