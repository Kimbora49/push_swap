/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InsertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:17:46 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/05 17:52:32 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	insertionsort(t_list **a, t_list **b)
{
    int i;
	int lena;
    
	lena = 2;
    i = 0;
    ra(a);
    ra(a);
    while((*a)->next->next != NULL)
         pb(a, b);
    if((*a)->data > (*a)->next->data)
        sa((*a));
    while ((*b) != NULL)
    {
        while((*b)->data > (*a)->data && i < lena)
        {
            i++;
            ra(a);
        }
		pa(a, b);
		lena++;
        while(i > 0)
        {
            rra(a);
            i--;
        }
    }
    return ;
}
