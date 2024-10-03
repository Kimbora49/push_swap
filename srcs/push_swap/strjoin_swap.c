/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:09:49 by amarzouk          #+#    #+#             */
/*   Updated: 2024/10/03 17:36:14 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
			write(2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
}

void	free_split(char **av)
{
	int	i;

	i = 0;
	if (!av || !*av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

char	**ft_join_args(char **av)
{
	char	*tmp;
	char	*str;
	char	**matrix;
	int		i;

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
