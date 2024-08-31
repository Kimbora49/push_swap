/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:01:48 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/31 17:08:43 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_check(char **av)
{
	int	j;
	int	y;

	j = 1;
	y = 0;
	while (av[j])
	{
		y = 0;
		while (av[j][y])
		{
			if (av[j][y] != 32 && av[j][y] != '\t')
				break ;
			y++;
		}
		if (!av[j][y])
		{
			write(2,"Error\n",6);
			exit(1);
		}
		j++;
	}
}

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
	init_node_a(&a, argv + 1);
	free_split(argv);
	if (!list_sorted(a))
	{
		if (list_len(a) == 2)
			sa(&a);
		if (list_len(a) == 3)
			ft_sort_3elem(&a);
		if (list_len(a) >= 3)
			sort_node(&a, &b);
	}
	free_list(&a);
	return (0);
}