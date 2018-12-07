/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:31:07 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/20 04:01:48 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	char	*csrc;

	i = ft_strlen(dest);
	csrc = (char *)src;
	while (*csrc)
	{
		dest[i] = *csrc;
		i++;
		csrc++;
	}
	dest[i] = '\0';
	return (dest);
}
