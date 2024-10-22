/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:39:54 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:39:55 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_lists **list)
{
	t_lists	*last_list;

	if (!*list || !(*list)->next)
		return ;
	last_list = find_last(*list);
	last_list->next = *list;
	last_list->next->prev = last_list;
	*list = (*list)->next;
	last_list->next->next = NULL;
	(*list)->prev = NULL;
}

void	ra(t_lists **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_lists **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_lists **a, t_lists **b)
{
	rotate(b);
	rotate(a);
	ft_printf("rr\n");
}
