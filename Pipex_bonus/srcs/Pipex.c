/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:29:12 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/24 19:05:49 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pipex_bonus.h"

void ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av, char **env)
{
	pipex_t *data;
	int pid;
	int i;
	char **cmd;
	char *path;

	i = 2;
	data = malloc(sizeof(pipex_t));
	if (ac >= 5)
	{
		open_files(data, av, ac);
		while(i < ac - 1)
		{
			pipe(data->fd);
			pid = fork();

			if (pid == 0)
			{
				cmd = ft_split(av[i], ' ');
				path = cmd_path(split_path(find_path_in_env(env)), cmd[0]);
				if (!path)
				{
					ft_putstr_fd(2, cmd[0]);
					ft_putstr_fd(2, ": command not found\n");
					exit(127);
				}
				dup2(data->infile, STDIN_FILENO);
				if (data->save_fd != -1)
					dup2(data->save_fd, 0);
				dup2(data->fd[1], STDOUT_FILENO);
				if (i == ac - 2)
					dup2(data->outfile, STDOUT_FILENO);
				if (execve(path, cmd, env) == -1)
				{
					perror(cmd[0]);
					exit(127);
				}
			}
			close (data->fd[1]);
			if (data->save_fd != -1)
				close(data->save_fd);
			data->save_fd = data->fd[0];
			i++;
		}
		close (data->infile);
		close(data->outfile);
		wait(NULL);
		
	}
	else
		printf("Invalid args\n");
}