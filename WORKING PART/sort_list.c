/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:17:18 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/21 17:10:10 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_a_to_b(t_list **a, t_list **b)
{
    t_list  *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median)
            && !(cheapest_node->target_node->above_median))
            rev_rotate_both(a, b, cheapest_node);
            prep_for_push(a, cheapest_node, 'a');
            prep_for_push(b, cheapest_node->target_node, 'b');
            pb(b, a);
}

static void move_b_to_a(t_list **a, t_list **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b);
}

static void min_on_top(t_list **a)
{
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if (find_min(*a)->above_median)
            ra(a);
        else
            rra(a);
    }
}
void    ft_sort_3elem(t_list **a)
{
	if(a->nbr > a->next->nbr)
	{
		if(a->nbr > a->next->next->nbr)
			ra(a);
	}
	else if(a->next->nbr > a->nbr)
	{
		if(a->next->nbr > a->next->next->nbr)
			rra(a);
	}
    if(a->nbr > a->next->nbr)
        sa(a);
}


void    sort_list(t_list **a, t_list **b)
{
    int len_a;

    len_a = list_len(*a);
    if (len_a-- > 3 && !list_sorted(*a))
        pb(b, a);
    if (len_a-- > 3 && !list_sorted(*a))
        pb(b, a);
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