/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:59:25 by kristori          #+#    #+#             */
/*   Updated: 2023/01/16 15:34:46 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc >= 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		reader = fork();
		if (reader == 0)
		{
			close(fd[0]);
			while (get_next_line(&line))
			{
				if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
					exit(EXIT_SUCCESS);
				write(fd[1], line, ft_strlen(line));
			}
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			wait(NULL);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	file_in;
	int	file_out;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			file_out = ft_open_file(argv[argc - 1], 0);
			ft_here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			file_out = ft_open_file(argv[argc - 1], 1);
			file_in = ft_open_file(argv[1], 2);
			dup2(file_in, STDIN_FILENO);
		}
		while (i < argc - 2)
			ft_child_process(argv[i++], envp);
		dup2(file_out, STDOUT_FILENO);
		ft_execute(argv[argc - 2], envp);
	}
	else
		return (1);
	return (0);
}
