/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:20:14 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/21 17:03:21 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void set_target_b(t_list *a, t_list *b)
{
    t_list  *current_a;
    t_list  *target_node;
    long    best_match_index;

    while(b)
    {
        best_match_index = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->nbr > b->nbr
                && current_a->nbr < best_match_index)
                {
                    best_match_index = current_a->nbr;
                    target_node = current_a;
                }
                current_a = current_a->next;
        }
        if (best_match_index == LONG_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void    init_nodes_b(t_list *a, t_list *b)
{
    init_index_median(a);
    init_index_median(b);
    set_target_b(a, b);
}