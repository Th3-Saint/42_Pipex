/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:23:49 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/23 14:38:11 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup( char *s1)
{
	char	*new;
	size_t	i;
	size_t	l;

	l = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * l + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!(s))
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	else
		p = malloc (sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			p[i] = ((char *)s)[start];
			i++;
			start++;
		}
		p[i] = '\0';
		return (p);
	}
}


char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));	

	i = 0;
	j = 0;
	while(s1[i])
		str[j++] = s1[i++];
	i = 0;
	while(s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);

}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < n -1)
		i++;
	return (s1[i] - s2[i]);
}
