/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:40:15 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:40:16 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_syntax(char *str)
{
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_lists *a, int n)
{
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_list(t_lists **list)
{
	t_lists	*tmp;
	t_lists	*current_list;

	if (!list)
		return ;
	current_list = *list;
	while (current_list)
	{
		tmp = current_list->next;
		current_list->nbr = 0;
		free(current_list);
		current_list = tmp;
	}
	*list = NULL;
}

void	free_errors(t_lists **a, char **av)
{
	free_list(a);
	free_split(av);
	write(2, "Error\n", 6);
	exit(1);
}
