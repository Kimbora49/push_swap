/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:24:35 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/05 17:47:38 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "push_swap.h"

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

int main(int argc, char *argv[])
{
	t_list	*listea;
	t_list	*listeb = NULL;

	listea = ft_parsing(argv);
    printf("listea :\n%d\n",listea->data);
    printf("%d\n",listea->next->data);
    printf("%d\n",listea->next->next->data);
	printf("%d\n",listea->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->next->next->next->data);
	printf("\nmoves(mouvements en francais) :\n");
	insertionsort(&listea, &listeb, argc);
	printf("\nfin des moves(mouvements en francais)\n\n");
    printf("listea :\n%d\n",listea->data);
    printf("%d\n",listea->next->data);
    printf("%d\n",listea->next->next->data);
	printf("%d\n",listea->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->next->next->data);
	printf("%d\n",listea->next->next->next->next->next->next->next->next->next->data);

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