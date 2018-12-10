/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:48:28 by jtaibi            #+#    #+#             */
/*   Updated: 2017/11/22 02:31:02 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char *s, char c)
{
	int	nb;

	nb = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			nb++;
		while (*s != c && *s)
			s++;
	}
	return (nb);
}

static int		count_len_word(char *s, int index, char c)
{
	int	len;

	len = 0;
	while (s[index + len] != c && s[index + len])
		len++;
	return (len);
}

static	char	**create_tab(char *s, char c)
{
	char	**tab;
	int		nbmots;
	int		index;
	int		i;

	nbmots = count_words(s, c);
	if ((tab = (char **)malloc((nbmots + 1) * sizeof(char *))) == NULL)
		return (NULL);
	tab[nbmots] = NULL;
	index = 0;
	i = 0;
	while (i < nbmots)
	{
		while (s[index] && s[index] == c)
			index++;
		tab[i] = (char *)malloc(count_len_word(s, index, c) * sizeof(char));
		if (tab[i] == NULL)
			return (NULL);
		while (s[index] && s[index] != c)
			index++;
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		len;
	int		i;
	int		x;

	if (!s)
		return (NULL);
	if ((new = create_tab((char *)s, c)) == NULL)
		return (NULL);
	i = 0;
	x = 0;
	while (new[i])
	{
		while (s[x] && s[x] == c)
			x++;
		len = count_len_word((char *)s, x, c);
		ft_strncpy(new[i], s + x, len);
		new[i][len] = '\0';
		while (s[x] && s[x] != c)
			x++;
		i++;
	}
	return (new);
}
