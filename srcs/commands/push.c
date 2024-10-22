/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:40:07 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:40:08 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_lists **dst, t_lists **src)
{
	t_lists	*list_push;

	if (!*src)
		return ;
	list_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	list_push->prev = NULL;
	if (!*dst)
	{
		*dst = list_push;
		list_push->next = NULL;
	}
	else
	{
		list_push->next = *dst;
		list_push->next->prev = list_push;
		*dst = list_push;
	}
}

void	pa(t_lists **a, t_lists **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_lists **b, t_lists **a)
{
	push(b, a);
	ft_printf("pb\n");
}
