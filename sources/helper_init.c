/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:49:23 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 20:44:33 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	list_len(t_node *list)
{
	int	i;

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
	t_node	*tmp;

	if (!list)
		return (0);
	tmp = list;
	max = LONG_MIN;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	while (max != list->nbr)
		list = list->next;
	return (list);
}

t_node	*find_min(t_node *list)
{
	long	min;
	t_node	*tmp;

	if (!list)
		return (0);
	tmp = list;
	min = LONG_MAX;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	while (min != list->nbr)
		list = list->next;
	return (list);
}
