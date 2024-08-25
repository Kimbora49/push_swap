/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_postpush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:35:40 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 12:37:30 by tmazan           ###   ########.fr       */
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

void	free_errors(t_node **list)
{
	free_list(list);
	ft_printf("Error\n");
	exit(1);
}
