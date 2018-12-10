/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:51:52 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/13 12:54:54 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnoctet(void *str, size_t n)
{
	unsigned char *cstr;

	cstr = (unsigned char *)str;
	while (n > 0)
	{
		ft_putchar(*cstr);
		cstr++;
		n--;
	}
}
