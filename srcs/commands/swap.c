/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:39:27 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:39:29 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_lists **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->next = (*head)->next;
	(*head)->prev->prev = *head;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_lists **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_lists **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_lists **a, t_lists **b)
{
	swap(b);
	swap(a);
	ft_printf("ss\n");
}
