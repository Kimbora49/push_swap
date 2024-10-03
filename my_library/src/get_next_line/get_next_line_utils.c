/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzouk <amarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:18:15 by amarzouk          #+#    #+#             */
/*   Updated: 2024/02/05 17:11:44 by amarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

int	len(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*chr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_str_init(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = 0;
	return (str);
}

char	*join(char *s1, char *s2)
{
	char	*strj;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_str_init();
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	strj = (char *)malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	if (!strj)
		return (0);
	while (s1[i])
	{
		strj[i] = s1[i];
		i++;
	}
	while (s2[j])
		strj[i++] = s2[j++];
	strj[len(s1) + len(s2)] = '\0';
	free(s1);
	return (strj);
}
