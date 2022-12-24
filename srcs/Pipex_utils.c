/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:23:01 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/23 14:38:19 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex.h"

void	open_files(pipex_t *data, char **av)
{
	data->infile = open(av[1], O_RDONLY , 0666);
	data->outfile = open(av[4], O_CREAT | O_RDWR , 0666);
	data->save_fd = -1;
	if (data->infile < 0)
	{
		perror(av[1]);
		exit(127);
	}
	else
		if (data->outfile < 0)
		{
			perror(av[4]);
			exit(127);
		}
}

char *find_path_in_env(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char **split_path(char *path)
{
	char **split_path;
	int i;

	i = 0;
	while(path[i] && path[i] != '=')
		i++;
	i += 1;
	split_path = ft_split(path + i, ':');
	return (split_path);
}

char *cmd_path(char **splited_path, char *cmd)
{
	int i;
	char *join;
	char *tmp;
	i = 0;

	while(splited_path[i])
	{
		tmp = ft_strjoin(splited_path[i], "/");

		join = ft_strjoin(tmp, cmd);
		// free(tmp);
		if (access(join, F_OK | X_OK) != -1)
			return (join);
		// free(join);
		i++;
	}
	return (NULL);
}