/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:21:10 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/08 11:55:17 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    sa(t_list *a)
{
    int temp;

    if(a->next)
    {
        temp = a->data;
        a->data = a->next->data;
        a->next->data = temp;
        printf("sa\n");
    }
    return ;
}//ok

void    sb(t_list *b)
{
    int temp;

    if(b->next)
    {
        temp = b->data;
        b->data = b->next->data;
        b->next->data = temp;
        printf("sb\n");
    }
    return ;
}//ok

void    ss(t_list *a, t_list *b)
{
    int temp;

    if(a->next)
    {
        temp = a->data;
        a->data = a->next->data;
        a->next->data = temp;
    }
    if(b->next)
    {
        temp = b->data;
        b->data = b->next->data;
        b->next->data = temp;
    }
    printf("ss\n");
    return ;
}//ok

void    pa(t_list **a, t_list **b)
{
	t_list	*btemp;

    if(*b == NULL)
		return ;
	btemp = *b;
	*b = btemp->next;
	btemp->next = *a;
	*a = btemp;
    printf("pa\n");
    return ; 
}//ok

void    pb(t_list **a, t_list **b)
{
	t_list	*atemp;

    if(*a == NULL)
		return ;
	atemp = *a;
	*a = atemp->next;
	atemp->next = *b;
	*b = atemp;
    printf("pb\n");
    return ; 
}//ok

void    ra(t_list **a)
{
	t_list	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *a;
	*a = (*a)->next;
	node->next->next = NULL;
	write(1, "ra\n", 3);
}//ok

void    rb(t_list **b)
{
	t_list	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *b;
	*b = (*b)->next;
	node->next->next = NULL;
	write(1, "rb\n", 3);
}//ok

void    rr(t_list **a, t_list **b)
{
    t_list	*node;

    if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *b;
	*b = (*b)->next;
	node->next->next = NULL;
	node = *a;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *a;
	*a = (*a)->next;
	node->next->next = NULL;
    printf("rr\n");
    return ;
}//ok

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