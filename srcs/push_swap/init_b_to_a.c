/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:40:27 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:40:28 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b(t_lists *a, t_lists *b)
{
	t_lists	*current_a;
	t_lists	*target_list;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_list = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_list = find_min(a);
		else
			b->target_list = target_list;
		b = b->next;
	}
}

void	init_nodes_b(t_lists *a, t_lists *b)
{
	init_index_median(b);
	init_index_median(a);
	set_target_b(a, b);
}
