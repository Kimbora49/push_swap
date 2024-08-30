/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:01:48 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/30 21:59:56 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	// printf("appel init_node_a\n"); //tmp
	init_node_a(&a, argv + 1);
	if (!list_sorted(a))
	{
		if (list_len(a) == 2)
		{
			// printf("list_len == 2\n"); //tmp
			sa(&a);
		}
		if (list_len(a) == 3)
		{
			// printf("list_len == 3\n"); //tmp
			ft_sort_3elem(&a);
		}
		else
		{
			// printf("sort_node\n"); //tmp
			sort_node(&a, &b);
		}
	}
	// printf("_free_\n"); //tmp	
	free_list(&a);
	return (0);
}
