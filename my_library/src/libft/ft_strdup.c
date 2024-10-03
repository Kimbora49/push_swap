/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman_marzouk <ayman_marzouk@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:01:19 by amarzouk          #+#    #+#             */
/*   Updated: 2024/01/03 22:53:42 by ayman_marzo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return (dest);
}
