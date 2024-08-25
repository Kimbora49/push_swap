/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:51:45 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 12:31:17 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void    pa(t_node **a, t_node **b)
{
	t_node	*btemp;

    if(*b == NULL)
		return ;
	btemp = *b;
	*b = btemp->next;
	btemp->next = *a;
	*a = btemp;
    printf("pa\n");
    return ; 
}//ok

void    pb(t_node **a, t_node **b)
{
	t_node	*atemp;

    if(*a == NULL)
		return ;
	atemp = *a;
	*a = atemp->next;
	atemp->next = *b;
	*b = atemp;
    printf("pb\n");
    return ; 
}//ok