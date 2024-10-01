/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:49:23 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/01 20:00:08 by tmazan           ###   ########.fr       */
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
		return (NULL);
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
