/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:53:40 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/30 13:59:01 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
void	sa(t_node **a)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	*b = (*b)->next;
	(*b)->prev->prev = *b;
	(*b)->prev->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = (*b)->prev;
	(*b)->next = (*b)->prev;
	(*b)->prev = NULL;
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	*b = (*b)->next;
	(*b)->prev->prev = *b;
	(*b)->prev->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = (*b)->prev;
	(*b)->next = (*b)->prev;
	(*b)->prev = NULL;
	printf("ss\n");
}
