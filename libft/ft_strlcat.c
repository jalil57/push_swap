/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:15 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/24 17:25:07 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len1;
	size_t len2;

	i = 0;
	len1 = ft_strlen(dest);
	len2 = ft_strlen((char *)src);
	if (size <= len1)
		return (len2 + size);
	while (i < size - len1 - 1 && src[i])
	{
		dest[len1 + i] = src[i];
		i++;
	}
	dest[len1 + i] = '\0';
	return (len1 + len2);
}
