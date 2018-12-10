/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_modifier2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:35:02 by jtaibi            #+#    #+#             */
/*   Updated: 2018/12/06 05:38:32 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

long long int	no_flag_signed(va_list arg)
{
	signed int	ret;

	ret = va_arg(arg, int);
	return ((long long int)ret);
}

long long int	no_flag(va_list arg)
{
	unsigned int	ret;

	ret = va_arg(arg, unsigned int);
	return ((long long int)ret);
}
