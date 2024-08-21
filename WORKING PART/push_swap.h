/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:56:48 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/21 17:46:46 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//cleaner_postpush
void	free_list(t_list **list);

//init_a_to_b
void    init_index_median(t_list *list);
static void set_target_a(t_list *a, t_list *b);
static void cost_analysis_a(t_list *a, t_list *b);
void    set_cheapest(t_list * list);
void    init_nodes_a(t_list *a, t_list *b);

//init_b_to_a
static void set_target_b(t_list *a, t_list *b);
void        init_nodes_b(t_list *a, t_list *b);

//helper_init
int list_len(t_list *list);
t_list	*find_max(t_list *list);
t_list	*find_min(t_list *list);

//split
int		count_word(char *str);
int		word_len(char *str, int i);
char 	**ft_split(char *str);

//helper_prepush
void	prep_for_push(t_list **list, t_list *top_node, char list_name);
bool        list_sorted(t_list *lst);

//sort_list
static void move_a_to_b(t_list **a, t_list **b);
static void move_b_to_a(t_list **a, t_list **b);
static void min_on_top(t_list **a);
void        ft_sort_3elem(t_list **a);
void        sort_list(t_list **a, t_list **b);

//move
    //swap
void    sa(t_list *a);
void    sb(t_list *b);
void    ss(t_list *a, t_list *b);

    //push
void    pa(t_list **a, t_list **b);
void    pb(t_list **a, t_list **b);

    //rotate
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);

    //reverse_rotate
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);

// PROTOTYPES
typedef struct s_list
{
    int             nbr;
    int             index;
    int             push_cost; //le nombre de coup pour le ranger au bon endroit
    bool            above_median;
    bool            cheapest;
    struct  s_list  *target_node;
    struct  s_list  *next;
    struct  s_list  *prev;
}   t_list;


#endif