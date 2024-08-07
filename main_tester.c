/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:24:35 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/07 15:53:42 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "push_swap.h"
int movcounter = 0;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*u;

	u = *lst;
	if (new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (u->next != NULL)
	{
		u = u->next;
	}
	if (u->next == NULL)
	{
		u->next = new;
	}
	return ;
}

t_list *ft_lstnew(int lettre)
{
	t_list *lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew == NULL)
	{
		return NULL;
	}
	lstnew->data = lettre;
	lstnew->next = NULL;
	return  (lstnew); 
}

t_list  *ft_parsing(char *argv[])
{
	int i;
	t_list *origin;

	i = 1;
	origin = ft_lstnew(atoi(argv[i]));
	i++;
	while(argv[i])
	{
		ft_lstadd_back(&origin, ft_lstnew(atoi(argv[i])));
		i++;
	}
	return (origin);
}
void    ra(t_list **a)
{
	t_list	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *a;
	*a = (*a)->next;
	node->next->next = NULL;
	write(1, "ra\n", 3);
	movcounter++;
}//ok

void    sa(t_list *a)
{
    int temp;

    if(a->next)
    {
        temp = a->data;
        a->data = a->next->data;
        a->next->data = temp;
        printf("sa\n");
		movcounter++;
    }
    return ;
}//ok

void    rra(t_list **a)
{
	t_list	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *a;
	*a = node->next;
	node->next = NULL;
	write(1, "rra\n", 4);
	movcounter++;
}//ok

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
	movcounter++;
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
	movcounter++;
    return ; 
}//ok

int    ft_circuit(t_list *temp, int i)
{
	t_list temp2;

	temp2 = temp;
	while(i != temp2->data)
	{
		if(temp2->next == NULL)
			return (1);
		temp2 = temp2->next;
	}
	return (0);
}

int ft_nodouble(char *argv[])
{
	int i;
	t_list *liste;
	t_list *listenext;
	
	i = 0;
	while (argv[i])
	{
		while (ft_circuit(liste, atoi(argv[i]) == 1))
		{
			listenext->data = atoi(argv[i]);
			listenext = listenext->next;
			i++;
		}
	}
	return (0);	
}


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

int ft_input_checker(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if(argc == 1)
        return (-1);
	while (argv[i])
	{
		if (atoll(argv[i]) > 2147483647)
			return (0);
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	if(ft_nodouble(argv) == 0)
		return (0);
	return (1);
}

int main(int argc, char *argv[])
{
	t_list	*listea;
	t_list	*listeb = NULL;
	if(ft_input_checker(argc, argv) != 1)
	{
		if(ft_input_checker(argc, argv) == 0)
			write(2, "Error\n", 6);
		return (0);
	}
	listea = ft_parsing(argv);
	printf("\nmoves(mouvements en francais) :\n");
	insertionsort(&listea, &listeb);
	printf("%d", movcounter);
	printf("\nfin des moves(mouvements en francais)\n\n");
    printf("listea :\n%d\n",listea->data);
	while (listea->next)
    {
		printf("%d\n",listea->data);
		listea = listea->next;
	}
}

/*TESTER FOR PARSING*/
// int main(int argc, char *argv[])
// {
// 	t_list *liste;
// 	(void)argc;
	
// 	liste = ft_parsing(argv);
//     printf("%d\n",liste->data);
//     printf("%d\n",liste->next->data);
//     printf("%d\n",liste->next->next->data);
// 	printf("%d\n",liste->next->next->next->data);
// 	return (0);
// }


// 4
// 4
// 5
// 6
// 7
// 8
// 84
// 124
// 254
// 654