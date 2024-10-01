/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/01 16:32:29 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	rra(t_node **a)
{
	t_node	*node;

	if (!*a || !(*a)->next)
		return ;
	node = find_last(*a);
	node->prev->next = NULL;
	node->next = *a;
	node->prev = NULL;
	*a = node;
	node->next->prev = node;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	t_node	*node;

	if (!*b || !(*b)->next)
		return ;
	node = find_last(*b);
	node->prev->next = NULL;
	node->next = *b;
	node->prev = NULL;
	*b = node;
	node->next->prev = node;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*node;
	t_node	*node2;

	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	node = find_last(*a);
	node->prev->next = NULL;
	node->next = *a;
	node->prev = NULL;
	*a = node;
	node->next->prev = node;
	node2 = find_last(*b);
	node2->prev->next = NULL;
	node2->next = *b;
	node2->prev = NULL;
	*b = node2;
	node2->next->prev = node2;
	write(1, "rrr\n", 4);
}
