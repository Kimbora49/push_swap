/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:39:47 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:39:48 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_lists **a, t_lists **b, t_lists *cheapest_node)
{
	while (*b != cheapest_node->target_list && *a != cheapest_node)
		rr(a, b);
	init_index_median(*b);
	init_index_median(*a);
}

static void	rev_rotate_both(t_lists **a, t_lists **b, t_lists *cheapest_node)
{
	while (*b != cheapest_node->target_list && *a != cheapest_node)
		rrr(a, b);
	init_index_median(*b);
	init_index_median(*a);
}

static void	move_a_to_b(t_lists **a, t_lists **b)
{
	t_lists	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_list->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_list->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_list, 'b');
	pb(b, a);
}

static void	move_b_to_a(t_lists **a, t_lists **b)
{
	prep_for_push(a, (*b)->target_list, 'a');
	pa(a, b);
}

void	sort_lists(t_lists **a, t_lists **b)
{
	int	lena;

	lena = list_len(*a);
	if (lena-- > 3 && !list_sorted(*a))
		pb(b, a);
	if (lena-- > 3 && !list_sorted(*a))
		pb(b, a);
	while (lena-- > 3 && !list_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	init_index_median(*a);
	min_on_top(a);
}
