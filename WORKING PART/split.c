/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:35:39 by ddifalla          #+#    #+#             */
/*   Updated: 2024/08/21 23:32:25 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_word(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			cnt++;
		}
	}
	return (cnt);
}

int		word_len(char *str, int i)
{
	int cnt;

	cnt = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		cnt++;
		i++;
	}
	return (cnt);
}

char 	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char *) * (count_word(str) + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			k = 0;
			if (!(tab[j] = malloc(sizeof(char) * (word_len(str, i) + 1))))
				return (NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				tab[j][k++] = str[i++]; // segfault 
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
