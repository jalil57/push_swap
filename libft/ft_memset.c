/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:44:47 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/13 20:45:47 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
		n--;
	}
	return (s);
}
