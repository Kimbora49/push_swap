/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:46 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/29 22:59:37 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	ra(t_node **a)
{
	t_node	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = find_last(*a);
	(*a)->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	node->next->prev = node;
	node->next->next = NULL;
	write(1, "ra\n", 3);
	return ; 
}

void	rb(t_node **b)
{
	t_node	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = find_last(*b);
	(*b)->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	node->next->prev = node;
	node->next->next = NULL;
	write(1, "rb\n", 3);
	return ; 
}

void	rr(t_node **a, t_node **b)
{
	t_node	*node;
	t_node	*node2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = find_last(*a);
	(*a)->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	node->next->prev = node;
	node->next->next = NULL;
	node2 = find_last(*b);
	(*b)->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	node2->next->prev = node2;
	node2->next->next = NULL;
	write(1, "rr\n", 3);
	return ; 
}
