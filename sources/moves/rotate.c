/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:46 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 20:39:51 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	ra(t_node **a)
{
	t_node	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *a;
	*a = (*a)->next;
	node->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *b;
	*b = (*b)->next;
	node->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	t_node	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *b;
	*b = (*b)->next;
	node->next->next = NULL;
	node = *a;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *a;
	*a = (*a)->next;
	node->next->next = NULL;
	printf("rr\n");
	return ;
}
