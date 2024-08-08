/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TurkAlgorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:56:13 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/08 15:49:52 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_max_min_b(t_list **a, t_list **b, int maxdatab, int mindatab)
{
	if(b->data > b->next->data)
	{
		maxdatab = b->data;
		mindatab = b->next->data;
	}
	else if(b->data < b->next->data)
	{
		maxdatab = b->next->data;
		mindatab = b->data;
	}
}
int		ft_maxb(t_list **b)
{
	int max;
	t_list *tmp;

	tmp = b;
	max = b->data;
	while(tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void    ft_sort_3elema(t_list **a)
{
	if(a->data > a->next->data)
	{
		if(a->data > a->next->next->data)
			ra(a);
	}
	else if(a->next->data > a->data)
	{
		if(a->next->data > a->next->next->data)
			rra(a);
	}
    if(a->data > a->next->data)
        sa(a);
}
int	ft_movcounter(t_list **a, t_list **b, int target, int medianea, int medianeb)
{
	int nbmoves;
	t_list	*targetnode;
	t_list	*node;
	t_list	tmpa;
	t_list	tmpb;	

	tmpa = a;
	tmpb = b;
	node = a;
	targetnode = b;
	while (target != targetnode->data) //pour retrouver la node qui correspond a la data "target"
		targetnode = targetnode->next;
	if (node->data == a->data && targetnode->data == b->data)	//si la nodetarget et la node est au sommet de B alors 0 moves 
		return (0);
		//A CHAQUE "MOVE" on incremente nbmove (en faisant le move sur la tmpa/b)
	if(node->data == a->data || targetnode->data == b->data) // SI soit la node A soit la data est au sommet de sa liste
		if(node->data == a->data)
		{
			if (targetnode->index < medianeb)
			{
				while(targetnode->index > 0)
				{
					temprb(tmpb);
					nbmoves++;
				}
				return (nbmoves);
			}
			else
			{
				while(targetnode->index > 0)
				{
					temprrb(tmpb);
					nbmoves++;
				}
				return (nbmoves);
			}
		}
		else
		{
			if (target->index < medianea)
			{
				while(target->index > 0)
				{
					tempra(tmpa);
					nbmoves++;
				}
				return (nbmoves);
			}
			else
			{
				while(target->index > 0)
				{
					temprra(tmpa);
					nbmoves++;
				}
				return (nbmoves);
			}
		}
			// alors pas de double moves (rr/rrr)
			// donc ra/rb ou rra/rrb jusqu'a ce que celui pas au sommet soit au sommet

		//SI les deux ne sont pas au sommet de leur liste alors
		while(target->index > medianea && targetnode->index > medianea)// sinon SI tout les deux au dessus de la mediane alors RR jusqu'a ce qu'1 des deux soit au sommet
		{
			temprr();
			nbmoves++;
		}
		if(target->index == 0)
		{
			while(targetnode->index != 0)
			{
				temprb();
				nbmoves++;
			}
		}
		else if (targetnode->index == 0)
		{
			while(target->index != 0)
			{
				tempra();
				nbmoves++;
			}
		}
		if (target->index == 0 && targetnode->index == 0)
			return (nbmoves);
		while(target->index < medianea && targetnode->index < medianea)// sinon SI tout les deux au dessus de la mediane alors RR jusqu'a ce qu'1 des deux soit au sommet
		{
			temprrr();
			nbmoves++;
		}
		if(target->index == 0)
		{
			while(targetnode->index != 0)
			{
				temprrb();
				nbmoves++;
			}
		}
		else if (targetnode->index == 0)
		{
			while(target->index != 0)
			{
				temprra();
				nbmoves++;
			}
		}
		if (target->index == 0 && targetnode->index == 0)
			return (nbmoves);
	}//puis rra/rrb (l'autre) jusqu'a ce qu'il soit au sommet	
		// sinon SI les deux "desynchronisés" (un au dessus un en dessous) alors pas de double moves (rr/rrr)
			// ra/rra jusqu'a ce qu'il soit au sommet puis rb/rrb jusqu'a ce qu'il soit au sommet
}

int	ft_data_target_node(int a->data, t_list **b)
{
	int closestsmaller;
	int nbsmaller;
	t_list *tmp;

	nbsmaller = 0;
	tmp = b;
	closestsmaller = b->data;
	while(tmp)
	{
		if (tmp->data > closestsmaller && tmp->data < a->data)
		{
			closestsmaller = tmp->data;
			nbsmaller++;
		}
		tmp = tmp->next;
	}
	if (nbsmaller == 0)
	{
		if (closestsmaller > a->data)
			closestsmaller = ft_maxb(b);
	}
	return (closestsmaller);
}

int    ft_turk(t_list **a, t_list **b, int lena, int lenb)
{
	int	mindatab;
	int	maxdatab;
	int nbmoves;
	int medianea;
	int medianeb;
	
	medianea = lena / 2;
	medianeb = lenb / 2;
	while (lena > 3 && lenb < 2)
	{
		pb(a, b);
		lena--;
		lenb++;
	}
	if(lena == 3)
		ft_sort_3elema(a);
	ft_max_min_b(a, b, maxdatab, mindatab);
	nbmoves = ft_movcounter(a, b, ft_target_node(a->data, b), medianea, medianeb);
	return (0);
}
