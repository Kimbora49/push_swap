/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_prepush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:10:48 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 12:47:15 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	prep_for_push(t_node **list, t_node *top_node, char list_name)
{
	while (*list != top_node) //Check if the required node is not already the first node
	{
		if (list_name == 'a') //If not, and it is list `a`, execute the following
		{
			if (top_node->above_median)
				ra(list);
			else
				rra(list);
		}
		else if (list_name == 'b') //If not, and it is list `b`, execute the following
		{
			if (top_node->above_median)
				rb(list);
			else
				rrb(list);
		}	
	}
}
bool    list_sorted(t_node *lst)
{
    if(!lst)
        return (1);
    while(lst->next)
    {
        if (lst->nbr > lst->next->nbr)
            return (false);
        lst = lst->next;
    }
    return (true);
}