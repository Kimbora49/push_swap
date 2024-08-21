/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:51:45 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/21 16:51:49 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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