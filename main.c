/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:19 by kristori          #+#    #+#             */
/*   Updated: 2022/11/30 15:23:31 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(pipefd) < 0)
			perror("Error");
		pid = fork();
		if (pid < 0)
			perror("Fork: ");
		if (!pid)
			ft_child_one(pipefd, fd[0], argv, envp);
		else
			ft_child_two(pipefd, fd[1], argv, envp);
	}
	else
		write(2, "Error argv\n", 11);
}

void	ft_child_one(int *pipefd, int fd, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	cmd = ft_split(argv[2], ' ');
	ft_check_split(cmd);
	close(pipefd[0]);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
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

void	ft_child_two(int *pipefd, int fd, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	cmd = ft_split(argv[3], ' ');
	ft_check_split(cmd);
	close(pipefd[1]);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
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
