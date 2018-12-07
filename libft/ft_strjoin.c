/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:27:33 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/20 13:44:46 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		attribution(int *i, int *x)
{
	*i += 1;
	*x += 1;
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	int		i;
	int		x;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if ((new = (char *)malloc(len * sizeof(char))) == NULL)
		return (NULL);
	x = 0;
	i = 0;
	while (s1[i])
	{
		new[x] = s1[i];
		attribution(&i, &x);
	}
	i = 0;
	while (s2[i])
	{
		new[x] = s2[i];
		attribution(&i, &x);
	}
	new[x] = '\0';
	return (new);
}
