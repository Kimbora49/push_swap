/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:51:18 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 12:37:19 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	append_node(t_node **list, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!list)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*list))
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*list);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_node *find_last(t_node *list)
{
    while(list->next)
    {
        list = list->next;
    }
    return (list);
}

int	error_syntax(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+'
			|| *s == '-')
		&& !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_node_a(t_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);			
		append_node(a, (int)n);
		i++;
	}
}
