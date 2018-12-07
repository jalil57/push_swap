/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:11:35 by jtaibi            #+#    #+#             */
/*   Updated: 2018/12/05 14:57:00 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcreate(size_t size, char c)
{
	char	*array;

	if (!(array = ft_strnew(size)))
		return (NULL);
	ft_memset(array, c, size);
	return (array);
}
