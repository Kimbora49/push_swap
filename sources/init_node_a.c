/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:51:18 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/01 20:04:16 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	append_node(t_node **list, int n)
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
	node->cheapest = 0;
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

t_node	*find_last(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	error_syntax(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
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

static long	ft_atol(const char *s, t_node **a, char **av)
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
			sign = -1;
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

void	init_node_a(t_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!error_syntax(argv[i]))
			free_errors(a, argv);
		n = ft_atol(argv[i], a, argv);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, argv);
		if (error_duplicate(*a, (int)n))
			free_errors(a, argv);
		append_node(a, (int)n);
		i++;
	}
}
