/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:21:27 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/07 12:21:20 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void		replace_sign(char *line, char sign)
{
	char	*where;

	if (!(where = ft_strchr(line, sign)))
		return ;
	*where = '0';
	*line = sign;
}
