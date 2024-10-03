/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:03:59 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/10/03 17:11:27 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_lists **a)
{
	t_lists	*biggest_list;

	biggest_list = find_max(*a);
	if (biggest_list == *a)
		ra(a);
	else if ((*a)->next == biggest_list)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	min_on_top(t_lists **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
