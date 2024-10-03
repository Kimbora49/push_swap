/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:22:35 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/03 17:42:28 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	list_len(t_lists *list)
{
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_lists	*find_last(t_lists *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	list_sorted(t_lists *list)
{
	while (list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}

t_lists	*find_min(t_lists *list)
{
	long	min;
	t_lists	*min_list;

	if (!list)
		return (NULL);
	min = LONG_MAX;
	while (list)
	{
		if (list->nbr < min)
		{
			min = list->nbr;
			min_list = list;
		}
		list = list->next;
	}
	return (min_list);
}

t_lists	*find_max(t_lists *list)
{
	long	max;
	t_lists	*max_list;

	if (!list)
		return (NULL);
	max = LONG_MIN;
	while (list)
	{
		if (list->nbr > max)
		{
			max = list->nbr;
			max_list = list;
		}
		list = list->next;
	}
	return (max_list);
}
