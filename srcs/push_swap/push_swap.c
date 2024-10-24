/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:40:44 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:40:45 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_lists	*a;
	t_lists	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	ft_check(av);
	av = ft_join_args(av);
	init_list_a(&a, av);
	free_split(av);
	if (!list_sorted(a))
	{
		if (list_len(a) == 2)
			sa(&a);
		else if (list_len(a) == 3)
			sort_three(&a);
		else
			sort_lists(&a, &b);
	}
	free_list(&a);
}
