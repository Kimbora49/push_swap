/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:10:50 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/10/03 17:33:47 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_library/inc/ft_printf.h"
# include "../my_library/inc/libft.h"
# include "../my_library/inc/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_lists
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	int				cheapest;
	struct s_lists	*target_list;
	struct s_lists	*next;
	struct s_lists	*prev;
}						t_lists;

void	pa(t_lists **a, t_lists **b);
void	pb(t_lists **b, t_lists **a);
void	rra(t_lists **a);
void	rrb(t_lists **b);
void	rrr(t_lists **a, t_lists **b);
void	ra(t_lists **a);
void	rb(t_lists **b);
void	rr(t_lists **a, t_lists **b);
void	sa(t_lists **a);
void	sb(t_lists **b);
void	ss(t_lists **a, t_lists **b);

int		error_syntax(char *str);
int		error_duplicate(t_lists *a, int n);
void	free_list(t_lists **list);
void	free_errors(t_lists **a, char **av);
void	init_list_a(t_lists **a, char **av);
char	**split(char *s, char c);
void	init_nodes_a(t_lists *a, t_lists *b);
void	init_nodes_b(t_lists *a, t_lists *b);
void	init_index_median(t_lists *list);
void	set_cheapest(t_lists *list);
t_lists	*get_cheapest(t_lists *list);
void	prep_for_push(t_lists **s, t_lists *n, char c);
int		list_len(t_lists *list);
t_lists	*find_last(t_lists *list);
int		list_sorted(t_lists *list);
t_lists	*find_min(t_lists *list);
t_lists	*find_max(t_lists *list);
void	swap(t_lists **head);
void	push(t_lists **dst, t_lists **src);
void	rotate(t_lists **list);
void	rev_rotate(t_lists **list);
void	ft_check(char **av);
void	sort_three(t_lists **a);
void	sort_lists(t_lists **a, t_lists **b);
void	min_on_top(t_lists **a);
void	free_split(char **s2);
char	**ft_join_args(char **av);

#endif