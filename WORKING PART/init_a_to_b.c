/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:33:13 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/21 17:04:48 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_index_median(t_list *list)
{
	int i;
	int median;

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
		++i;
	}
}

static void set_target_a(t_list *a, t_list *b)
{
	t_list  *current_b;
	t_list  *target_node;
	long    best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void cost_analysis_a(t_list *a, t_list *b)
{
	int len_a;
	int len_b;

	len_a = list_len(a);
	len_b = list_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if(!(a->above_median))
			a->push_cost = len_a - (a->index);
		if(a->target_node->above_median)
			a->push_cost = a->push_cost + a->target_node->index;
		else
			a->push_cost = a->push_cost + (len_b - (a->target_node->index));
		a = a->next;
	}
}

void    set_cheapest(t_list * list)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!list)
		return ;
	cheapest_value = LONG_MAX;
	while (list)
	{
		if (list->push_cost < cheapest_value)
		{
			cheapest_value = list->push_cost;
			cheapest_node = list;
		}
		list = list->next;
	}
	cheapest_node->cheapest = true;
}

void    init_nodes_a(t_list *a, t_list *b)
{
	init_index_median(a);
	init_index_median(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
