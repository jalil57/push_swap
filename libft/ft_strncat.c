/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:46:49 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/19 21:37:14 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	char	*csrc;

	i = ft_strlen(dest);
	csrc = (char *)src;
	while (n-- && *csrc)
	{
		dest[i] = *csrc;
		csrc++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
