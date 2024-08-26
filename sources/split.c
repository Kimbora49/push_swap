/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:35:39 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/26 22:07:17 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_countword(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
		else if (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (count);
}

int	ft_lenword(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

void	freeing(size_t i, char **dest)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
}

char	**ft_addword(char **dest, char *str, size_t nbwords)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nbwords)
	{
		while (str[j] && (str[j] == ' ' || str[j] == '\t'))
			j++;
		dest[i] = ft_substr(str, j, ft_lenword(&str[j]));
		if (!dest[i])
		{
			freeing(i, dest);
			return (NULL);
		}
		while (str[j] && str[j] != ' ' && str[j] != '\t')
			j++;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char *s)
{
	char	**dest;
	size_t	nbwords;

	if (!s)
		return (NULL);
	nbwords = ft_countword(s);
	dest = malloc(sizeof(char *) * (nbwords + 1));
	if (!dest)
		return (NULL);
	dest = ft_addword(dest, s, nbwords);
	return (dest);
}
