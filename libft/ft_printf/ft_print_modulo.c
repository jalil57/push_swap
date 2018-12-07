/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_modulo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:59:33 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/06 05:14:37 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

char		*print_modulo(t_spec *spec, va_list arg)
{
	char	*conv;

	(void)arg;
	conv = ft_strdup("%");
	if (spec->champ > 1)
		gestion_champ(spec, &conv);
	return (conv);
}
