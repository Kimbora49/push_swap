/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/29 22:49:44 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	rra(t_node **a)
{
	t_node	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = find_last(*a);
	node->prev->next = NULL;
	node->next = *a;
	node->prev = NULL;
	*a = node;
	node->next->prev = node;
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_node **b)
{
	t_node	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = find_last(*b);
	node->prev->next = NULL;
	node->next = *b;
	node->prev = NULL;
	*b = node;
	node->next->prev = node;
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*node;
	t_node	*node2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
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
	return ;
}
