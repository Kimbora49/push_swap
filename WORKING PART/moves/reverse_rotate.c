/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:52:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/21 16:52:29 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    rra(t_list **a)
{
	t_list	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *a;
	*a = node->next;
	node->next = NULL;
	write(1, "rra\n", 4);
}//ok

void    rrb(t_list **b)
{
	t_list	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *b;
	*b = node->next;
	node->next = NULL;
	write(1, "rrb\n", 4);
}//ok

void    rrr(t_list **a, t_list **b)
{
    t_list	*node;

    if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *b;
	*b = node->next;
	node->next = NULL;
	node = *a;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *a;
	*a = node->next;
	node->next = NULL;
    printf("rrr\n");
    return ;
}//ok