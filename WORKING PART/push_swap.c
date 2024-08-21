/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:01:48 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/21 17:27:35 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], " ");
    init_list_a(&a, argv + 1);
    if (!list_sorted(a))
    {
        if (list_len(a) == 2)
            sa(&a);
        else if (list_len(a) == 3)
            ft_sort_3elem(&a);
        else
            sort_list(&a, &b);
    }
    free_list(&a);
    return (0);
}