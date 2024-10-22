/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:40:35 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:40:36 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *s, t_lists **a, char **av)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && (*s
					- 48) > LONG_MAX % 10))
			free_errors(a, av);
		result = result * 10 + (*s++ - 48);
	}
	return (result * sign);
}

static void	append_node(t_lists **list, int n)
{
	t_lists	*node;
	t_lists	*last_node;

	if (!list)
		return ;
	node = malloc(sizeof(t_lists));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*list))
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*list);
		node->prev = last_node;
		last_node->next = node;
	}
}

void	init_list_a(t_lists **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a, av);
		n = ft_atol(av[i], a, av);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, av);
		if (error_duplicate(*a, (int)n))
			free_errors(a, av);
		append_node(a, (int)n);
		i++;
	}
}

t_lists	*get_cheapest(t_lists *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->cheapest)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	prep_for_push(t_lists **list, t_lists *top_node, char list_name)
{
	while (*list != top_node)
	{
		if (list_name == 'a')
		{
			if (top_node->above_median)
				ra(list);
			else
				rra(list);
		}
		else if (list_name == 'b')
		{
			if (top_node->above_median)
				rb(list);
			else
				rrb(list);
		}
	}
}
