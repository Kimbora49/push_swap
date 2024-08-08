/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:24:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/08 13:36:24 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool ft_is_stack_sorted(t_list **a)
{
    while(a->next)
    {
        while(a->data < a->next->data)
            a = a->next;
    }
    if(a->next == NULL)
        return (1);
    return (0);
}