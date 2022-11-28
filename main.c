/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:19 by kristori          #+#    #+#             */
/*   Updated: 2022/11/28 15:39:30 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int	pipefd[2];
	int	fd[2];
	int	status;

	if (argc == 5)
	{
		// if (pipe(pipefd) < 0)
		// 	printf("Error\n");
		pipe(pipefd);
		printf("%d\n", pipe(pipefd));
		pid = fork();
		printf("%d\n", (pid_t) pid);
		if (pid == (pid_t) 0)
		{
			ft_child_one(pipefd, fd[0], argv, envp);
			return (EXIT_SUCCESS);
		}
		else if (pid < (pid_t) 0)
		{
			printf("Error\n");
			return (EXIT_FAILURE);
		}
		else
		{
			ft_child_two(pipefd, fd[1], argv, envp);
			return (EXIT_SUCCESS);
		}
	}
}

int	ft_child_one(int *pipefd, int fd, char **argv, char **envp)
{
	char	**cmdargs;
	char	**path;
	char	*cmd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	cmdargs = ft_split(argv[2], ' ');
	close(pipefd[0]);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	//path = ft_parsing(envp);
	//controllare con access()
	// i = -1;
	// while (path[++i])
	// {
	// 	cmd = ft_strjoin(path[i], argv[2]);
	// 	execve(cmd, cmdargs, envp);
	// 	free(cmd);
	// }
	return (EXIT_FAILURE);
}

int	ft_child_two(int *pipefd, int fd, char **argv, char **envp)
{
	char	**cmdargs;
	char	**path;
	char	*cmd;
	int		i;

	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		exit(EXIT_FAILURE);
	cmdargs = ft_split(argv[3], ' ');
	close(pipefd[1]);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	cmdargs = ft_split(argv[3], ' ');
	path = ft_parsing(envp);
	i = -1;
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], argv[3]);
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	return (EXIT_FAILURE);
}
