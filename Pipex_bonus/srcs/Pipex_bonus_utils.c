/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:23:01 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/24 19:36:15 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex_bonus.h"

int here_doc(char *delemeter)
{
	char *str;
	int fd[2];

	pipe(fd);
	write(1, "here_doc> ", 10);
	str = get_next_line(0);
	while (ft_strncmp(str, delemeter, ft_strlen(delemeter) + 1))
	{
		write(1, "here_doc> ", 10);
		write(fd[1], str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	close (fd[1]);
	return (fd[0]);
}

void	open_files(pipex_t *data, char **av, int ac, int *i)
{
	if (!ft_strncmp("here_doc", av[1], 8))
	{
		*i = 3;
		data->infile = here_doc(av[2]);
		data->outfile = open(av[ac - 1], O_CREAT | O_APPEND | O_WRONLY, 0666);
		
	}
	else
	{
		data->infile = open(av[1], O_RDONLY , 0666);
		data->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		data->save_fd = -1;
	}
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