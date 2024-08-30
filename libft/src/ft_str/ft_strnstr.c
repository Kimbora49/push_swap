/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:46:49 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/30 15:46:50 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0) 
		return ((char *) big);
	while (*big != '\0' && n-- >= little_len) 
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0) 
			return ((char *)big);
		big++;
	}
	return (NULL); 
}
