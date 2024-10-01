/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:01:48 by ddifalla          #+#    #+#             */
/*   Updated: 2024/10/01 17:37:44 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	ft_check(argv);
	argv = ft_join_args(argv);
	init_node_a(&a, argv);
	free_split(argv);
	if (!list_sorted(a))
	{
		if (list_len(a) == 2)
			sa(&a);
		else if (list_len(a) == 3)
			ft_sort_3elem(&a);
		else
			sort_node(&a, &b);
	}
	free_list(&a);
}
