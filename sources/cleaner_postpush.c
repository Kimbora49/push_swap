/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_postpush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:35:40 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/01 16:55:08 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_list(t_node **list)
{
	t_node	*tmp;
	t_node	*current;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*list = NULL;
}

void	free_errors(t_node **list, char **av)
{
	free_list(list);
	free_split(av);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_check(char **av)
{
	int	j;
	int	y;

	j = 1;
	y = 0;
	while (av[j])
	{
		y = 0;
		while (av[j][y])
		{
			if (av[j][y] != 32 && av[j][y] != '\t')
				break ;
			y++;
		}
		if (!av[j][y])
		{
			write(2,"Error\n",6);
			exit(1);
		}
		j++;
	}
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

char    **ft_join_args(char **av)
{
    char    *tmp;
    char    *str;
    char    **matrix;
    int        i;

    i = 1;
    tmp = ft_strjoin(av[i++], " ");
    while (av[i])
    {
        str = ft_strjoin(tmp, av[i]);
        free(tmp);
        tmp = ft_strjoin(str, " ");
        free(str);
        i++;
    }  
    matrix = ft_split(tmp, ' ');
    free(tmp);
    return (matrix);
}
