/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:40:00 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:40:02 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rev_rotate(t_lists **list)
{
	t_lists	*last_list;

	if (!*list || !(*list)->next)
		return ;
	last_list = find_last(*list);
	last_list->next = *list;
	*list = last_list;
	last_list->next->prev = last_list;
	last_list->prev->next = NULL;
	last_list->prev = NULL;
}

void	rra(t_lists **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_lists **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_lists **a, t_lists **b)
{
	rev_rotate(b);
	rev_rotate(a);
	ft_printf("rrr\n");
}
