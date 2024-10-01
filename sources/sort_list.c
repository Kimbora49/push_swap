/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:17:18 by ddifalla          #+#    #+#             */
/*   Updated: 2024/10/01 20:14:14 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	init_index_median(*a);
	init_index_median(*b);
}

static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	init_index_median(*a);
	init_index_median(*b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, true);
		else
			rra(a);
	}
}

void	ft_sort_3elem(t_node **a) 
{
	t_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_node(t_node **a, t_node **b)
{
	int	len_a;

	len_a = list_len(*a);
	if (len_a-- > 3 && !list_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !list_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !list_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	ft_sort_3elem(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	init_index_median(*a);
	min_on_top(a);
}
