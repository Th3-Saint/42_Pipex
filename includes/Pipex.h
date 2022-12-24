/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:26:01 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/23 14:28:20 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct pipex
{
	int fd[2];
	int infile;
	int outfile;
	int save_fd;
}	pipex_t;

char	**ft_split(char  *s, char c);
int	ft_strlen(char *str);
char	*ft_strdup( char *s1);
char	*ft_substr(char  *s, unsigned int start, size_t len);
char *ft_strjoin(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, size_t n);
void	open_files(pipex_t *data, char **av);
char *find_path_in_env(char **env);
char **split_path(char *path);
char *cmd_path(char **splited_path, char *cmd);
#endif