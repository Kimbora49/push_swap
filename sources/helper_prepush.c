/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_prepush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:10:48 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/01 20:10:38 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	prep_for_push(t_node **list, t_node *top_node, char list_name)
{
	while (*list != top_node)
	{
		if (list_name == 'a')
		{
			if (top_node->above_median)
				ra(list, true);
			else
				rra(list);
		}
		else if (list_name == 'b')
		{
			if (top_node->above_median)
				rb(list, true);
			else
				rrb(list);
		}
	}
}

int	list_sorted(t_node *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}
