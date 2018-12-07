/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:17:08 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/24 17:03:31 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int n;
	int nb;

	n = 1;
	nb = 0;
	if (*nptr == '\200')
		return (0);
	while ((*nptr <= ' ' || *nptr == 127) && *nptr != '\e')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			n = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	return (nb * n);
}
