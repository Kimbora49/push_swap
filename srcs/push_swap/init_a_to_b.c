/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:05:49 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/10/03 17:35:26 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_index_median(t_lists *list)
{
	int	median;
	int	i;

	i = 0;
	if (!list)
		return ;
	median = list_len(list) / 2;
	while (list)
	{
		list->index = i;
		if (i <= median)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		i++;
	}
}

static void	set_target_a(t_lists *a, t_lists *b)
{
	t_lists	*actual_b;
	t_lists	*target_list;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		actual_b = b;
		while (actual_b)
		{
			if (actual_b->nbr < a->nbr && actual_b->nbr > best_match_index)
			{
				best_match_index = actual_b->nbr;
				target_list = actual_b;
			}
			actual_b = actual_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_list = find_max(b);
		else
			a->target_list = target_list;
		a = a->next;
	}
}

static void	cost_analysis_a(t_lists *a, t_lists *b)
{
	int	lena;
	int	lenb;

	lena = list_len(a);
	lenb = list_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = lena - (a->index);
		if (a->target_list->above_median)
			a->push_cost += a->target_list->index;
		else
			a->push_cost += lenb - (a->target_list->index);
		a = a->next;
	}
}

void	set_cheapest(t_lists *list)
{
	long	cheapest_value;
	t_lists	*cheapest_list;

	if (!list)
		return ;
	cheapest_value = LONG_MAX;
	while (list)
	{
		if (list->push_cost < cheapest_value)
		{
			cheapest_list = list;
			cheapest_value = list->push_cost;
		}
		list = list->next;
	}
	cheapest_list->cheapest = 1;
}

void	init_nodes_a(t_lists *a, t_lists *b)
{
	init_index_median(b);
	init_index_median(a);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
