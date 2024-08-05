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

void	insertionsort(t_list **a, t_list **b, int argc)
{
    int i;
    
    i = 0;
    ra(a);
    ra(a);
    while((*a)->next->next != NULL)
         pb(a, b);
    if((*a)->data > (*a)->next->data)
        sa((*a));
    while ((*b)->next != NULL)
    {
        while((*b)->data > (*a)->data && i < argc - 1)
        {
            i++;
            ra(a);
        }
        pa(a, b);
        while(i > 0)
        {
            rra(a);
            i--;
        }
    }
    return ;
}

        //    4 4 6 7 8 124 254 5          A
        //       654 84     B