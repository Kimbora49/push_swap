/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:56:48 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/26 22:19:27 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <unistd.h>
// # include <stdlib.h>
// # include <stdarg.h>

# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <limits.h> //To define MIN and MAX macros
# include "../libft/libft.h"

// PROTOTYPES
typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost; //le nombre de coup pour le ranger au bon endroit
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//cleaner_postpush
void		free_list(t_node **list);
void		free_errors(t_node **list);

//init_a_to_b
void		init_index_median(t_node *list);
void		set_target_a(t_node *a, t_node *b);
void		cost_analysis_a(t_node *a, t_node *b);
void		set_cheapest(t_node *list);
void		init_nodes_a(t_node *a, t_node *b);

//init_b_to_a
void		set_target_b(t_node *a, t_node *b);
void		init_nodes_b(t_node *a, t_node *b);

//helper_init
int			list_len(t_node *list);
t_node		*find_max(t_node *list);
t_node		*find_min(t_node *list);
t_node		*get_cheapest(t_node *list);

//split
int			count_word(char *str);
int			word_len(char *str, int i);
char		**ft_split(char *s);

//helper_prepush
void		prep_for_push(t_node **list, t_node *top_node, char list_name);
bool		list_sorted(t_node *lst);
void		rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
void		rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node);

//sort_node
void		move_a_to_b(t_node **a, t_node **b);
void		move_b_to_a(t_node **a, t_node **b);
void		min_on_top(t_node **a);
void		ft_sort_3elem(t_node **a);
void		sort_node(t_node **a, t_node **b);

//move
	//swap
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);

	//push
void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);

	//rotate
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);

	//reverse_rotate
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);

//init_node_a
void		append_node(t_node **list, int n);
t_node		*find_last(t_node *list);
int			error_syntax(char *s);
int			error_duplicate(t_node *a, int n);
void		init_node_a(t_node **a, char **argv);

#endif