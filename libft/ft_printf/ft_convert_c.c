/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:47:50 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/07 11:54:38 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char		*convert_c(t_spec *spec, va_list arg)
{
	unsigned char	ret;
	char			*conv;

	if (!(ret = va_arg(arg, int)))
	{
		conv = ft_strdup("^@");
		spec->count++;
		if (spec->champ > 0)
			spec->champ++;
	}
	else
	{
		conv = ft_strnew(1);
		*conv = ret;
	}
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	return (conv);
}
