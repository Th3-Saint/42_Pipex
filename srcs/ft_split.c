/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:24:36 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/23 14:37:59 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex.h"

static size_t	nbr_str(const char *s, char c)
{
	size_t	i;
	size_t	nbrstr;

	i = 0;
	nbrstr = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\t')
			i++;
		else
		{
			while (s[i] != c && s[i] != '\t' && s[i])
				i++;
			nbrstr++;
		}
	}
	return (nbrstr);
}

char	**ft_split(char  *s, char c)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	p = malloc(sizeof(char *) * (nbr_str(s, c) + 1));
	if (!p)
		return (NULL);
	while (j < nbr_str(s, c))
	{
		while (s[i] == c || s[i] == '\t')
			i++;
		k = i;
		while (s[i] != c && s[i] != '\t' && s[i])
			i++;
		p[j++] = ft_substr(s, k, i - k);
	}
	p[j] = NULL;
	return (p);
}
