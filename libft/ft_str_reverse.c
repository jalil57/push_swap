/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:12:33 by jtaibi            #+#    #+#             */
/*   Updated: 2018/12/05 20:39:37 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_str_reverse(char *str)
{
	int		i;
	int		len;
	char	swap;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len - i)
	{
		swap = str[i];
		str[i] = str[len - i];
		str[len - i] = swap;
		i++;
	}
}
