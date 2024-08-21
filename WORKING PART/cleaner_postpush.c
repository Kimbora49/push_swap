/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_postpush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:35:40 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/21 17:13:32 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list) //Define a function to free a list if there are errors
{
	t_list	*tmp; //To store the next node in the list before the current node is freed, because once a node is freed, you can't access its next pointer
	t_list	*current;

	if (!list) //Check for an empty list
		return ;
	current = *list;
	while (current) //As long as a node exist in the list
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp;
	}
	*list = NULL;
}
