/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:49:23 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/21 17:03:26 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_len(t_list *list)
{
    int i;

    i = 0;
    while(list)
    {
        list = list->next;
        i++;
    }
    return (i);
}

t_list	*find_max(t_list *list)
{
	long 	max;
	t_list	*tmp;

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

t_list	*find_min(t_list *list)
{
	long 	min;
	t_list	*tmp;

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
