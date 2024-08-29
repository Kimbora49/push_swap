/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:51:45 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/29 23:15:20 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*btemp;

	if (*b == NULL)
		return ;
	btemp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	btemp->prev = NULL;
	if (!*a)
	{
		*a = btemp;
		btemp->next = NULL;
	}
	else
	{
		btemp->next = *a;
		btemp->next->prev = btemp;
		*a = btemp;
	}
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*atemp;

	if (*a == NULL)
		return ;
	atemp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	atemp->prev = NULL;
	if (!*b)
	{
		*b = atemp;
		atemp->next = NULL;
	}
	else
	{
		atemp->next = *b;
		atemp->next->prev = atemp;
		*b = atemp;
	}
	write(1, "pb\n", 3);
	return ;
}
