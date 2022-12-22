/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:29:12 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/22 18:47:21 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

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

void	open_files(pipex_t *data, char **av)
{
	data->infile = open(av[1], O_RDONLY | 0666);
	data->outfile = open(av[4], O_CREAT, O_WRONLY | 0666);
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

int ft_strncmp(char *s1, char *s2, int len)
{
	int i;
	
	i = 0;
	while(s1[i] == s2[i] && i < len - 1)
		i++;
	return (s1[i] - s2[i]);
}

char *find_path_in_env(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		if (!ft_strncmp("PATH", env[i], 5))
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

int main(int ac, char **av, char **env)
{
	pipex_t *data;
	int pid;
	int i;
	char **cmd;
	char *path;

	i = 2;
	data = malloc(sizeof(pipex_t));
	if (ac == 5)
	{
		open_files(data, av);
		while(i < ac - 1)
		{
			if (pipe(data->fd))
			perror(NULL);
			pid = fork();

			if (pid == 0)
			{
				cmd = ft_split(av[i], ' ');
				path = cmd_path(split_path(find_path_in_env(env)), cmd[0]);
				printf("%s\n", path);
				exit(0);
				dup2(data->infile, STDIN_FILENO);
				if (data->save_fd != -1)
					dup2(data->save_fd, 0);
				dup2(data->fd[1], STDOUT_FILENO);
				if (i == ac - 2)
					dup2(data->outfile, STDOUT_FILENO);
				
				
				execve(path, cmd, env);
			
			}
			close (data->fd[1]);
			if (data->save_fd != -1)
				close(data->save_fd);
			data->save_fd = data->fd[0];
			i++;
		wait (NULL);
		}
		close (data->infile);
		close(data->outfile);
		// while (pid != -1)
		// 	waitpid(-1, NULL, 0);
	}
	else
		printf("INnvalid args\n");
}