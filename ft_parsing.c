/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:54:26 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/05 14:28:01 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list  *ft_parsing(char *argv[])
{
	int		i;
	t_list	*origin;

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