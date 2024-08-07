/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:12:59 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/07 15:16:31 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

