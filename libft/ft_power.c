/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:57:18 by jtaibi            #+#    #+#             */
/*   Updated: 2018/12/05 20:40:31 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_power(long long number, int power)
{
	long long	result;

	if (power == 0)
		return (1);
	if (power == 1)
		return (number);
	result = number;
	while (power-- && result * number <= __LONG_LONG_MAX__)
		result *= number;
	return (result);
}
