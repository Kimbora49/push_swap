/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 12:31:33 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void    rra(t_node **a)
{
	t_node	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *a;
	*a = node->next;
	node->next = NULL;
	write(1, "rra\n", 4);
}//ok

void    rrb(t_node **b)
{
	t_node	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *b;
	*b = node->next;
	node->next = NULL;
	write(1, "rrb\n", 4);
}//ok

void    rrr(t_node **a, t_node **b)
{
    t_node	*node;

    if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *b;
	*b = node->next;
	node->next = NULL;
	node = *a;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *a;
	*a = node->next;
	node->next = NULL;
    printf("rrr\n");
    return ;
}//ok