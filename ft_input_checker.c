/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:09:29 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/07 15:41:30 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
