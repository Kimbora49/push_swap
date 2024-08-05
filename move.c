/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:25:45 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/05 14:29:41 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list *ft_lstnew(void *lettre)
{
    t_list *lstnew;

    lstnew = (t_list *)malloc(sizeof(t_list));
    if (lstnew == NULL)
    {
        return NULL;
    }
    lstnew->content = lettre;
    lstnew->next = NULL;
    return  (lstnew); 
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (del == NULL || *lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
	{
		return ;
	}
	del(lst->content);
	free(lst);
	return ;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
	{
		return ;
	}
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
	{
		return ;
	}
	del(lst->content);
	free(lst);
	return ;
}

void ft_lstdellast(t_list *lst, void (*del)(void*))
{
    if (lst == NULL || del == NULL)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	del(lst->content);
	free(lst);
	return ;
}