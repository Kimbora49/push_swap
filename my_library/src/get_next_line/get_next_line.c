/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:42:21 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/22 22:42:23 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*read_string(int fd, char *str)
{
	char	*tmp;
	int		len;

	tmp = malloc(((size_t)BUFFER_SIZE + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	len = 1;
	while (!chr(str, '\n') && (len != 0))
	{
		len = read(fd, tmp, BUFFER_SIZE);
		if (len == -1)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		tmp[len] = '\0';
		str = join(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*copy_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*skip_and_free(char *full_string)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	while (full_string[i] != '\0' && full_string[i] != '\n')
		i++;
	if (full_string[i] == '\0')
	{
		free(full_string);
		return (NULL);
	}
	new_string = malloc(sizeof(char) * (len(full_string) - i + 1));
	if (!new_string)
		return (NULL);
	i++;
	j = 0;
	while (full_string[i] != '\0')
		new_string[j++] = full_string[i++];
	new_string[j] = '\0';
	free(full_string);
	if (new_string[0] == '\0')
		return (free(new_string), NULL);
	return (new_string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = read_string(fd, buffer);
	if (!buffer)
		return (NULL);
	line = copy_line(buffer);
	buffer = skip_and_free(buffer);
	if (!line)
		return (NULL);
	return (line);
}
