/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:35:39 by ddifalla          #+#    #+#             */
/*   Updated: 2024/09/07 02:36:54 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// int	ft_countword(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != ' ' && str[i] != '\t')
// 		{
// 			count++;
// 			while (str[i] && str[i] != ' ' && str[i] != '\t')
// 				i++;
// 		}
// 		else if (str[i] == ' ' || str[i] == '\t')
// 			i++;
// 	}
// 	return (count);
// }

// int	ft_lenword(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] && str[i] != ' ' && str[i] != '\t')
// 		i++;
// 	return (i);
// }

// void	freeing(size_t i, char **dest)
// {
// 	while (i > 0)
// 	{
// 		i--;
// 		free(dest[i]);
// 	}
// 	free(dest);
// }

// char	**ft_addword(char **dest, char *str, size_t nbwords)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < nbwords)
// 	{
// 		while (str[j] && (str[j] == ' ' || str[j] == '\t'))
// 			j++;
// 		dest[i] = ft_substr(str, j, ft_lenword(&str[j]));
// 		if (!dest[i])
// 		{
// 			freeing(i, dest);
// 			return (NULL);
// 		}
// 		while (str[j] && str[j] != ' ' && str[j] != '\t')
// 			j++;
// 		i++;
// 	}
// 	dest[i] = NULL;
// 	return (dest);
// }

// char	**split(char *s)
// {
// 	char	**dest;
// 	size_t	nbwords;

// 	if (!s)
// 		return (NULL);
// 	nbwords = ft_countword(s);
// 	dest = malloc(sizeof(char *) * (nbwords + 1));
// 	if (!dest)
// 		return (NULL);
// 	dest = ft_addword(dest, s, nbwords);
// 	return (dest);
// }

static int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				count++;
				inside_word = 1;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
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