/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:25:25 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/20 04:03:20 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *little)
{
	int i;
	int x;

	if (little[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		x = 0;
		while (little[x] == str[i + x])
		{
			if (!little[x + 1])
				return ((char *)(str + i));
			x++;
		}
		i++;
	}
	return (NULL);
}
