/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:19 by kristori          #+#    #+#             */
/*   Updated: 2022/12/02 12:26:30 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];
	int		fd[3];

	if (argc >= 5)
	{
		fd[2] = argc;
		if (pipe(pipefd) < 0)
			perror("Error");
		pid = fork();
		if (pid < 0)
			perror("Fork: ");
		if (!pid)
			ft_child_one(pipefd, fd, argv, envp);
		else
			ft_child_two(pipefd, fd, argv, envp);
	}
	else
		write(2, "Error argv\n", 11);
	return (1);
}

void	ft_child_one(int *pipefd, int *fd, char **argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	ft_check_fd1(fd, argv);
	dup2(fd[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	i = 2;
	while (i < fd[2] - 2)
	{
		cmd = ft_split(argv[i], ' ');
		ft_check_split(cmd);
		path = ft_path(cmd[0], envp);
		if (cmd[0] && path)
		{
			execve(path, cmd, envp);
			ft_free(cmd);
			free(path);
		}
		else
			ft_cmd_not_found(cmd);
		i++;
	}
}

void	ft_child_two(int *pipefd, int *fd, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	ft_check_fd2(fd, argv);
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	cmd = ft_split(argv[fd[2] - 2], ' ');
	ft_check_split(cmd);
	path = ft_path(cmd[0], envp);
	if (cmd[0] && path)
	{
		execve(path, cmd, envp);
		ft_free(cmd);
		free(path);
	}
	else
		ft_cmd_not_found(cmd);
}
