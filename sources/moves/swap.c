/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:53:40 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/25 12:37:31 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void    sa(t_node *a)
{
    int temp;

    if(a->next)
    {
        temp = (*a)->nbr;
        (*a)->nbr = (*a)->next->nbr;
        (*a)->next->nbr = temp;
        printf("sa\n");
    }
    return ;
}//ok

void    sb(t_node *b)
{
    int temp;

    if(b->next)
    {
        temp = (*b)->nbr;
        (*b)->nbr = (*b)->next->nbr;
        (*b)->next->nbr = temp;
        printf("sb\n");
    }
    return ;
}//ok

void    ss(t_node *a, t_node *b)
{
    int temp;

    if(a->next)
    {
        temp = (*a)->nbr;
        (*a)->nbr = (*a)->next->nbr;
        (*a)->next->nbr = temp;
    }
    if(b->next)
    {
        temp = (*b)->nbr;
        (*b)->nbr = (*b)->next->nbr;
        (*b)->next->nbr = temp;
    }
    printf("ss\n");
    return ;
}//ok