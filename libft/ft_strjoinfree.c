/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:24:49 by jtaibi            #+#    #+#             */
/*   Updated: 2018/12/06 03:18:30 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, int to_free)
{
	char	*array;

	array = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(array, s1);
	ft_strcpy(array + ft_strlen(s1), s2);
	if (to_free == 1 || to_free == 3)
		free(s1);
	if (to_free == 2 || to_free == 3)
		free(s2);
	return (array);
}
