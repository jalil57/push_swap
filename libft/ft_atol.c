/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:05:34 by jtaibi            #+#    #+#             */
/*   Updated: 2018/12/09 10:05:56 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int n;
	long int nb;

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
