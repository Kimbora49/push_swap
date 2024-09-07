/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_postpush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:35:40 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/07 02:36:53 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_list(t_node **list)
{
	t_node	*tmp;
	t_node	*current;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*list = NULL;
}

void	free_errors(t_node **list, char **av)
{
	free_list(list);
	free_split(av);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
	{
		free(argv[i++]);
	}
	free(argv);
}
