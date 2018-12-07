/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:27:42 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/23 20:46:55 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char*)dest;
	csrc = (char*)src;
	if (csrc < cdest)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
		ft_memcpy(cdest, csrc, n);
	return (cdest);
}
