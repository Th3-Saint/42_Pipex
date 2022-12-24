/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:23:49 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/24 19:34:26 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex_bonus.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	if(!s2 || !s1)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n -1)
		i++;
	return (s1[i] - s2[i]);
}
