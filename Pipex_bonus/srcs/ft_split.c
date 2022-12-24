/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:24:36 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/24 18:23:24 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex_bonus.h"

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
