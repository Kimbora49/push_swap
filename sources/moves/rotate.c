/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:46 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/01 16:39:55 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	ra(t_node **a, bool printing)
{
	t_node	*node;

	if (!*a || !(*a)->next)
		return ;
	node = find_last(*a);
	node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	node->next->prev = node;
	node->next->next = NULL;
	if (printing)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, bool printing)
{
	t_node	*node;

	if (!*b || !(*b)->next)
		return ;	
	node = find_last(*b);
	node->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	node->next->prev = node;
	node->next->next = NULL;
	if (printing)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, false);
	rb(b, false);
	write(1, "rr\n", 3);
}
